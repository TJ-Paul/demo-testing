# Database Query Processing — Complete Notes

> **Topics Covered:**
> 1. [Selection](#1-selection)
>    - [File Scan (A1)](#file-scan-a1---linear-scan)
>    - [Index Scan (A2–A10)](#index-scan)
>    - [Negation](#negation)
>    - [Bitmap Index Scan](#bitmap-index-scan)
> 2. [Join Operations](#2-join-operations)
>    - [Nested Loop Join](#1-nested-loop-join)
>    - [Block Nested Loop Join](#2-block-nested-loop-join)
>    - [Indexed Nested Loop Join](#3-indexed-nested-loop-join)
>    - [Merge Join](#4-merge-join)
>    - [Hash Join](#5-hash-join)
> 3. [Sorting — External Sort-Merge](#3-sorting--external-sort-merge)
>    - [Run Generation](#run-generation)
>    - [Merge Phase & Cost](#merge-phase--block-transfer-cost)

---

## Notation

| Symbol | Meaning |
|--------|---------|
| `bᵣ` | Number of blocks in relation r |
| `bₛ` | Number of blocks in relation s |
| `nᵣ` | Number of tuples in relation r |
| `tT` | Time for one block transfer |
| `tS` | Time for one disk seek |
| `hᵢ` | Height of index tree |
| `M` | Number of buffer blocks available in memory |
| `bb` | Number of buffer blocks used per run during merge |
| `b` | Number of blocks containing matching records |

---

## 1. Selection

### File Scan (A1) — Linear Scan

- `bᵣ` = number of blocks containing records from the relation.

**General Selection (Worst Case):**
$$\text{Cost} = b_r \cdot t_T + 1 \cdot t_S$$

**Selection on Key (Best Case):**
$$\text{Cost} = \frac{b_r}{2} \cdot t_T + 1 \cdot t_S$$

---

### Index Scan

#### A2 — Clustering Index, Equality on Key

Used for retrieving a **single record** that satisfies the equality condition.

- `hᵢ` = height of index tree.
- To navigate the index tree from root to leaf: `hᵢ` block transfers + `hᵢ` seeks.
- Plus **one** final block transfer and seek to retrieve the actual data block containing the record from the index table.

$$\text{Cost} = h_i(t_T + t_S) + (t_T + t_S) = (h_i + 1)(t_T + t_S)$$

---

#### A3 — Clustering Index, Equality on Non-Key

Used for retrieving **multiple records**.

- `b` = number of blocks containing matching records.
- `hᵢ (tT + tS)` — same as A2 (navigate the index).
- `+tS` — single seek required to move disk head to the start of the data blocks where matching begins.
- `+b × tT` — since the index is **clustering**, matching records are stored in consecutive blocks.

$$\text{Cost} = (t_S + t_T) \cdot h_i + t_S + b \times t_T$$

---

#### A4 — Secondary Index, Equality on Key / Non-Key

**Retrieve a single record (search key is a candidate key):**
$$\text{Cost} = (h_i + 1)(t_S + t_T)$$

**Retrieve multiple records (search key is NOT a candidate key):**

- In a secondary index, records are **not** stored consecutively on disk.
- If there are `n` matching records, each could be in a completely different block.
- So we need `n` full seeks and `n` transfers.

$$\text{Cost} = (h_i + n)(t_S + t_T) = h_i(t_S + t_T) + n(t_S + t_T)$$

---

#### A5 — Clustering Index, Comparison `σ_{A≤v}(r)` or `σ_{A≥v}(r)`

*(Uses clustering index for range queries)*

---

#### A6 — Non-Clustering Index, Comparison `σ_{A≤v}(r)` or `σ_{A≥v}(r)`

*(Uses non-clustering index for range queries)*

---

#### A7 — Conjunctive Selection Using One Index

For queries of the form `σ_{θ₁ ∧ θ₂ ∧ ... ∧ θₙ}(r)`.

Use one index to reduce candidates, then filter remaining conditions in memory.

---

#### A8 — Conjunctive Selection Using Composite Index

Use a composite index covering multiple attributes of the conjunctive condition directly.

---

#### A9 — Conjunctive Selection by Intersection of Identifiers

Use multiple indices (one per condition), retrieve record IDs from each, then **intersect** the identifier sets, and fetch only matching records.

---

#### A10 — Disjunctive Selection by Union of Identifiers

For `σ_{θ₁ ∨ θ₂ ∨ ... ∨ θₙ}(r)`.

Use multiple indices, retrieve record IDs from each, then take the **union** and fetch all matching records.

---

### Negation

For `σ_{¬θ}(r)`:

1. Use **linear scan** on the file.
2. If very few records satisfy `θ`, an index applicable to `θ` can be used (retrieve those, exclude them).

---

### Bitmap Index Scan

Bridges the gap between secondary index scan and linear file scan when the number of matching records is **not known before execution**.

> A **page** is the smallest unit of data that can be moved between disk and memory.

**How it works:**

**Phase 1 — Index Scan Phase:**
The system scans the index to find all relevant record IDs that match the query.

**Phase 2 — Bitmap Construction:**
Instead of fetching data immediately, it marks a **bitmap** — a string of 0s and 1s in RAM where each bit represents one specific page.

- **Bit = 0:** This page contains no records that match your query.
- **Bit = 1:** This page contains at least one record that matches your query.

**Example:** If the 42nd bit is 1, the DBMS only needs to fetch page 42 from disk **once** to get its record, instead of fetching it several times.

---

## 2. Join Operations

> **Example data (for context):**
> - No. of records of `std` = 5000; `takes` = 10000
> - No. of blocks of `std` = 100; `takes` = 400

---

### 1. Nested Loop Join

**Algorithm (`r ⋈ s`):**
```
for each tuple tᵣ in r do begin
    for each tuple tₛ in s do begin
        test pair (tᵣ, tₛ) to see if they satisfy the join condition
        if they do, add tᵣ · tₛ to the result
    end
end
```

- `r` = outer relation; `s` = inner relation
- `nᵣ` = number of tuples in relation r
- `bᵣ` = number of blocks in relation r
- `bₛ` = number of blocks in relation s

**Worst Case** *(only enough memory to hold one block of each relation)*:

$$\text{Block Transfers} = n_r \cdot b_s + b_r$$
$$\text{Seeks} = n_r + b_r$$

**If smaller relation fits entirely in memory** *(use that relation as inner)*:

$$\text{Block Transfers} = b_s + b_r$$
$$\text{Seeks} = 2$$

---

### 2. Block Nested Loop Join

**Worst Case:**
$$\text{Block Transfers} = b_r \cdot b_s + b_r$$
$$\text{Seeks} = 2 \cdot b_r$$

**Best Case:**
$$\text{Block Transfers} = b_r + b_s$$
$$\text{Seeks} = 2$$

#### Improvement to Block Nested Loop Algorithm

Use **M−2 disk blocks** as the blocking unit for the outer relation:

$$\text{Block Transfers} = \left\lceil \frac{b_r}{M-2} \right\rceil \times b_s + b_r$$

$$\text{Seek Cost} = 2\left\lceil \frac{b_r}{M-2} \right\rceil$$

---

### 3. Indexed Nested Loop Join

- `c` = cost of traversing the index and fetching all matching `s`-tuples for one tuple of `r`.

$$\text{Cost} = b_r(t_T + t_S) + n_r \cdot c$$

> `c` can be estimated as the cost of a **single selection on s** using the join condition.

---

### 4. Merge Join

$$\text{Cost} = (b_r + b_s) \text{ block transfers} + \left(\left\lceil \frac{b_r}{b_b} \right\rceil + \left\lceil \frac{b_s}{b_b} \right\rceil\right) \text{ seeks}$$

$$+ \text{ cost of sorting if relations are unsorted}$$

---

### 5. Hash Join

- Relation `s` is called the **build input**.
- Relation `r` is called the **probe input**.
- `nₕ` = number of hash buckets (partitions).
- `nₕ` must be at least $\left\lceil \frac{b_s}{M} \right\rceil$.

#### If recursive partitioning is NOT required:

$$\text{Cost} = 3(b_r + b_s) + 4n_h \text{ block transfers} + 2\left(\left\lceil \frac{b_r}{b_b} \right\rceil + \left\lceil \frac{b_s}{b_b} \right\rceil\right) \text{ seeks}$$

#### If recursive partitioning IS required:

$$\text{Block Transfers} = 2(b_r + b_s) \cdot \rho + b_r + b_s$$

$$\text{Seeks} = \left(2\left(\left\lceil \frac{b_r}{b_b} \right\rceil + \left\lceil \frac{b_s}{b_b} \right\rceil\right)\right) \cdot \rho$$

where $\rho$ = number of partitioning passes.

#### Special Case — If entire build input fits in main memory:

No partitioning is required.

$$\rho = \log_{\lfloor M/b_b \rfloor - 1}\left(\frac{b_s}{M}\right)$$

$$\text{Cost} = b_r + b_s$$

---

## 3. Sorting — External Sort-Merge

When a database relation is **too large to fit into available memory (RAM)**, the system cannot use standard in-memory algorithms like Quicksort. Instead it must use **external sort-merge**, which manages data by moving it in chunks between the disk and memory to produce a sorted result.

**Two phases:**
1. **Create sorted runs**
2. **Merge the runs (N-way merge)**

### Variables

| Symbol | Meaning |
|--------|---------|
| `bᵣ` | Total number of blocks/pages in a relation |
| `M` | Number of buffer blocks available in memory |
| `bb` | Number of buffer blocks used per run during merge |

---

### Run Generation

1. **Read** chunks of size `M` from disk.
2. **Sort** them in memory.
3. **Write** them back as sorted runs.

$$\text{Number of runs} = \left\lceil \frac{b_r}{M} \right\rceil$$

---

### Merge Phase & Block Transfer Cost

$$\left\lceil \frac{b_r}{M} \right\rceil = \left(\frac{M}{b_b} - 1\right)^p \implies \log_{\left(\frac{M}{b_b} - 1\right)}\left\lceil \frac{b_r}{M} \right\rceil = p = \text{pass count}$$

**Run Generation:**
- Read all blocks → `bᵣ`
- Write all blocks → `bᵣ`
- **Total: 2bᵣ**

**Each Merge Pass:**
- Read all blocks → `bᵣ`
- Write all blocks → `bᵣ`
- **Total: 2bᵣ** (except the final pass — output may go directly to the next operator, so we ignore the final write)

**Total Cost:**
$$\text{Total} = \text{Run Gen} + \text{Merge Passes} = 2b_r + p \cdot 2b_r - b_r$$
$$= p \cdot 2b_r + b_r = b_r(2p + 1)$$

$$\boxed{\therefore \text{Total Block Transfers} = b_r\left(2\log_{\left(\frac{M}{b_b}\right)-1}\left\lceil \frac{b_r}{M} \right\rceil + 1\right)}$$
