# 📚 Chapter 16: Query Optimization — Study Guide

> **Source:** Database System Concepts, 7th Ed. — Silberschatz, Korth and Sudarshan  
> **Purpose:** Term Final Exam Preparation

---

## 📋 Table of Contents

1. [Equivalence Rules & Expression Transformation](#1-equivalence-rules--expression-transformation-)
2. [Expression Trees (Query Trees)](#2-expression-trees-query-trees-)
3. [Cost-Based Query Optimization Steps](#3-cost-based-query-optimization-steps-)
4. [Evaluation Plans](#4-evaluation-plans-)
5. [Statistical Information for Cost Estimation](#5-statistical-information-for-cost-estimation-)
6. [Selection Size Estimation](#6-selection-size-estimation-)
7. [Join Size Estimation](#7-join-size-estimation-)
8. [Size Estimation for Other Operations](#8-size-estimation-for-other-operations-)
9. [Histograms](#9-histograms-)
10. [Dynamic Programming for Join Order Optimization](#10-dynamic-programming-for-join-order-optimization-)
11. [Left-Deep Join Trees](#11-left-deep-join-trees-)
12. [Interesting Sort Orders](#12-interesting-sort-orders-)
13. [Heuristic Optimization](#13-heuristic-optimization-)
14. [Materialized Views](#14-materialized-views-)
15. [Incremental View Maintenance](#15-incremental-view-maintenance-)
16. [Nested Subquery Optimization & Decorrelation](#16-nested-subquery-optimization--decorrelation-)
17. [Semijoin & Anti-Semijoin](#17-semijoin--anti-semijoin-)
18. [Halloween Problem](#18-halloween-problem-)
19. [Top-K Query Optimization](#19-top-k-query-optimization-)
20. [Importance Summary Table](#20-importance-summary-table)

---

## 1. Equivalence Rules & Expression Transformation ⭐⭐⭐⭐⭐

### What is it?
Rules that allow rewriting relational algebra expressions into **logically equivalent** forms — producing the same result but potentially with a lower execution cost.

Two expressions are **equivalent** if they generate the same set of tuples on every legal database instance.

### The Rules

| # | Rule | Description |
|---|---|---|
| 1 | **Conjunctive Selection Decomposition** | σ_θ1∧θ2(E) ≡ σ_θ1(σ_θ2(E)) |
| 2 | **Selection Commutativity** | σ_θ1(σ_θ2(E)) ≡ σ_θ2(σ_θ1(E)) |
| 3 | **Projection Cascading** | Π_L1(Π_L2(…(Π_Ln(E))…)) ≡ Π_L1(E), where L1 ⊆ L2 ⊆ … ⊆ Ln |
| 4a | **Selection + Cartesian Product → Join** | σ_θ(E1 × E2) ≡ E1 ⋈_θ E2 |
| 4b | **Selection + Join Merge** | σ_θ1(E1 ⋈_θ2 E2) ≡ E1 ⋈_θ1∧θ2 E2 |
| 5 | **Join Commutativity** | E1 ⋈ E2 ≡ E2 ⋈ E1 |
| 6a | **Natural Join Associativity** | (E1 ⋈ E2) ⋈ E3 ≡ E1 ⋈ (E2 ⋈ E3) |
| 6b | **Theta Join Associativity** | (E1 ⋈_θ1 E2) ⋈_θ2∧θ3 E3 ≡ E1 ⋈_θ1∧θ3 (E2 ⋈_θ2 E3), where θ2 involves only E2 and E3 |
| 7a | **Selection Distribution over Join (single side)** | σ_θ0(E1 ⋈ E2) ≡ (σ_θ0(E1)) ⋈ E2, if θ0 only has attributes from E1 |
| 7b | **Selection Distribution over Join (both sides)** | σ_θ1∧θ2(E1 ⋈ E2) ≡ (σ_θ1(E1)) ⋈ (σ_θ2(E2)) |
| 8a | **Projection Distribution over Join (simple)** | Π_L1∪L2(E1 ⋈_θ E2) ≡ Π_L1(E1) ⋈_θ Π_L2(E2), if θ only uses attrs from L1∪L2 |
| 9 | **Union/Intersection Commutativity** | E1 ∪ E2 ≡ E2 ∪ E1 (set difference is NOT commutative) |
| 10 | **Union/Intersection Associativity** | (E1 ∪ E2) ∪ E3 ≡ E1 ∪ (E2 ∪ E3) |
| 11 | **Selection over Set Ops** | σ_θ(E1 ∪ E2) ≡ σ_θ(E1) ∪ σ_θ(E2), same for ∩ and − |
| 12 | **Projection over Union** | Π_L(E1 ∪ E2) ≡ (Π_L(E1)) ∪ (Π_L(E2)) |
| 13 | **Selection over Aggregation** | σ_θ(G γ_A(E)) ≡ G γ_A(σ_θ(E)), provided θ only involves grouping attributes G |
| 14a | **Full Outerjoin Commutativity** | E1 ⟗ E2 ≡ E2 ⟗ E1 |
| 14b | **Left/Right Outerjoin Swap** | E1 ⟕ E2 ≡ E2 ⟖ E1 |
| 15 | **Selection over Outerjoin** | σ_θ1(E1 ⟕_θ E2) ≡ (σ_θ1(E1)) ⟕_θ E2, provided θ1 only involves E1 |
| 16 | **Outerjoin → Inner Join** | σ_θ1(E1 ⟕_θ E2) ≡ σ_θ1(E1 ⋈_θ E2), provided θ1 is null-rejecting on E2 |

> ⚠️ **Important:** Outerjoins are **NOT associative**: (r ⟕ s) ⟕ t ≢ r ⟕ (s ⟕ t)

### Key Transformation Example: Pushing Selections Down
```
-- Query: Find Music dept instructors and course titles

-- Before (initial):
Π_name,title ( σ_dept_name='Music' ( instructor ⋈ (teaches ⋈ Π_course_id,title(course)) ) )

-- After (using Rule 7a — push selection down):
Π_name,title ( (σ_dept_name='Music'(instructor)) ⋈ (teaches ⋈ Π_course_id,title(course)) )
```
**Why?** Filtering instructor first drastically reduces the number of tuples before the expensive join.

---

[🔝 Back to Top](#-table-of-contents)

---

## 2. Expression Trees (Query Trees) ⭐⭐⭐⭐⭐

### What is it?
A tree-based visual representation of a relational algebra expression.
- **Leaves** = Base relations
- **Internal nodes** = Relational operators (σ, Π, ⋈, etc.)
- Execution flows **bottom-up**

### Initial vs Transformed Tree
```
INITIAL TREE:                    TRANSFORMED TREE:
   Π_name,title                     Π_name,title
        |                                |
  σ_dept='Music'                        ⋈
        |                              / \
        ⋈                   σ_dept='Music'   ⋈
       / \                       |           / \
 instructor ⋈              instructor  σ_year=2017  Π_course_id,title
           / \                              |              |
       teaches Π_course_id,title        teaches          course
                   |
                 course
```

> 💡 **Exam Tip:** Practice drawing the initial tree from SQL, then apply equivalence rules to transform it.

---

[🔝 Back to Top](#-table-of-contents)

---

## 3. Cost-Based Query Optimization Steps ⭐⭐⭐⭐

### What is it?
The systematic process a query optimizer uses to find the cheapest execution plan.

### The 3 Steps
```
Step 1: Generate logically equivalent expressions
        → Use equivalence rules to produce alternative expressions

Step 2: Annotate expressions → Query Plans
        → Choose algorithm for each operator (e.g., hash join vs merge join)

Step 3: Choose cheapest plan
        → Estimate cost of each plan using statistics
        → Pick the one with minimum cost
```

### Cost Estimation is Based On:
- **Statistical info** about relations (tuple counts, distinct values)
- **Statistics for intermediate results** (to compute costs of sub-expressions)
- **Cost formulae** for algorithms (from Chapter 15)

> 📝 **Note:** Cost difference between plans can be enormous — seconds vs. days!

---

[🔝 Back to Top](#-table-of-contents)

---

## 4. Evaluation Plans ⭐⭐⭐

### What is it?
An evaluation plan specifies:
1. **What algorithm** is used for each operation (e.g., hash join, merge join, index scan)
2. **How execution is coordinated** (pipelined vs materialized)

### Viewing Plans in Real DBs
| Database | Command |
|---|---|
| PostgreSQL | `EXPLAIN ANALYZE <query>` |
| Oracle | `EXPLAIN PLAN FOR <query>` then `SELECT * FROM TABLE(DBMS_XPLAN.DISPLAY)` |
| SQL Server | `SET SHOWPLAN_TEXT ON` |

> PostgreSQL shows cost as **f..l** where f = cost to deliver first tuple, l = cost to deliver all results.

---

[🔝 Back to Top](#-table-of-contents)

---

## 5. Statistical Information for Cost Estimation ⭐⭐⭐⭐

### What is it?
Catalog statistics stored by the DBMS that the optimizer uses to estimate operation costs.

### Key Symbols

| Symbol | Meaning |
|---|---|
| **nᵣ** | Number of tuples in relation r |
| **bᵣ** | Number of disk blocks containing tuples of r |
| **lᵣ** | Size of a tuple in r (in bytes) |
| **fᵣ** | Blocking factor — number of tuples of r that fit in one block |
| **V(A, r)** | Number of **distinct values** of attribute A in r = \|Π_A(r)\| |

### Key Formula
$$b_r = \lceil n_r / f_r \rceil$$

### Estimation of Distinct Values After Operations

**After Selection σ_θ(r):**
- If θ is A = constant → V(A, σ_θ(r)) = 1
- If θ is A = v1 OR A = v2 OR … → V(A, σ_θ(r)) = number of specified values
- If θ is A op v → V(A, σ_θ(r)) = V(A, r) × s (where s = selectivity)
- Otherwise → min(V(A, r), n_σ_θ(r))

**After Join r ⋈ s:**
- If all attrs in A are from r → V(A, r ⋈ s) = min(V(A, r), n_{r⋈s})
- If A has attrs A1 from r and A2 from s → V(A, r ⋈ s) = min(V(A1,r)×V(A2-A1,s), V(A1-A2,r)×V(A2,s), n_{r⋈s})

---

[🔝 Back to Top](#-table-of-contents)

---

## 6. Selection Size Estimation ⭐⭐⭐⭐⭐

### What is it?
Formulas to estimate the number of tuples that will satisfy a selection condition.

### Case 1: Equality — σ_A=v(r)
```
Estimated tuples = nᵣ / V(A, r)

Special case: If A is a key → estimate = 1
```

### Case 2: Range — σ_A≤v(r)
```
If v < min(A, r)  →  c = 0

Otherwise:
c = nᵣ × (v - min(A, r)) / (max(A, r) - min(A, r))

If no stats available → c = nᵣ / 2
```

### Case 3: Complex Selections (Selectivity = sᵢ / nᵣ)

| Type | Formula |
|---|---|
| **Conjunction** σ_θ1∧θ2∧…∧θn(r) | nᵣ × (s1 × s2 × … × sn) / nᵣⁿ |
| **Disjunction** σ_θ1∨θ2∨…∨θn(r) | nᵣ × [1 - (1-s1/nᵣ)(1-s2/nᵣ)…(1-sn/nᵣ)] |
| **Negation** σ_¬θ(r) | nᵣ - size(σ_θ(r)) |

> 💡 **Exam Tip:** Conjunction assumes **independence** of conditions. Memorize all three formulas.

---

[🔝 Back to Top](#-table-of-contents)

---

## 7. Join Size Estimation ⭐⭐⭐⭐⭐

### What is it?
Formulas to estimate the number of tuples in the result of a join.

### Cases

| Condition | Estimated Output Size |
|---|---|
| R ∩ S = ∅ | nᵣ × nₛ (same as Cartesian product) |
| R ∩ S is a **key for R** | ≤ nₛ |
| R ∩ S is a **foreign key in S referencing R** | = nₛ |
| R ∩ S = {A}, not a key for either | min(nᵣ×nₛ / V(A,s), nᵣ×nₛ / V(A,r)) |

### Worked Example from Slides
```
student ⋈ takes  (join on ID)

nstudent = 5,000    fstudent = 50   bstudent = 100
ntakes   = 10,000   ftakes   = 25   btakes   = 400
V(ID, takes)   = 2500
V(ID, student) = 5000  ← primary key

Since ID in takes is a FOREIGN KEY referencing student:
  Result size = ntakes = 10,000

Without foreign key info:
  Estimate 1: 5000 × 10000 / 2500 = 20,000
  Estimate 2: 5000 × 10000 / 5000 = 10,000
  → Choose lower = 10,000 ✓ (matches foreign key result)
```

---

[🔝 Back to Top](#-table-of-contents)

---

## 8. Size Estimation for Other Operations ⭐⭐⭐

### What is it?
Quick formulas for estimating result sizes of non-join operations.

| Operation | Estimated Size |
|---|---|
| **Projection** Π_A(r) | V(A, r) |
| **Aggregation** G γ_A(r) | V(G, r) |
| **Union** r ∪ s | size(r) + size(s) |
| **Intersection** r ∩ s | min(size(r), size(s)) |
| **Difference** r − s | size(r) |
| **Left Outer Join** r ⟕ s | size(r ⋈ s) + size(r) |
| **Full Outer Join** r ⟗ s | size(r ⋈ s) + size(r) + size(s) |

> ⚠️ The set operation estimates are **upper bounds** and may be inaccurate.

---

[🔝 Back to Top](#-table-of-contents)

---

## 9. Histograms ⭐⭐⭐

### What is it?
Data structures that store the **frequency distribution** of attribute values, enabling more accurate cost estimation than simple min/max statistics.

### Types

| Type | Description |
|---|---|
| **Equi-Width** | Divides the value range into equal-sized buckets |
| **Equi-Depth** | Adjusts bucket boundaries so each bucket has ~equal number of tuples |

```
Example Equi-Depth breakpoints for age: (4, 8, 14, 19)
→ Each range has approximately the same number of people
```

### Additional Notes
- Many databases also store **n most-frequent values** separately
- Statistics may become **out of date** — use `ANALYZE` command in PostgreSQL to refresh
- Statistics are typically computed from a **random sample** of the data

---

[🔝 Back to Top](#-table-of-contents)

---

## 10. Dynamic Programming for Join Order Optimization ⭐⭐⭐⭐

### What is it?
An algorithm that finds the optimal join order for n relations **without** evaluating all possible orderings.

### Why is it Needed?
```
Number of join orders for n relations = (2(n-1))! / (n-1)!

n = 7  →  665,280 orders
n = 10 →  176,000,000,000+ orders  ← infeasible to check all!
```

### DP Solution
- Compute best plan for every **subset** of relations
- Store results → reuse when the same subset appears again
- **Time complexity (bushy trees):** O(3ⁿ) — for n=10 this is only ~59,000!
- **Space complexity:** O(2ⁿ)
- **For left-deep trees only:** O(n · 2ⁿ) time, O(2ⁿ) space

### findbestplan Algorithm
```
procedure findbestplan(S):
    if bestplan[S].cost ≠ ∞:
        return bestplan[S]     ← already computed, reuse it (memoization)

    if S has only 1 relation:
        set bestplan[S] based on best access method + selections + indices

    else:
        for each non-empty subset S1 of S where S1 ≠ S:
            P1 = findbestplan(S1)
            P2 = findbestplan(S - S1)
            for each join algorithm A:
                compute cost of joining P1 and P2 using A
                if cost < bestplan[S].cost:
                    update bestplan[S]

    return bestplan[S]
```

### Join Algorithm Cost Logic
```
If algorithm A is INDEXED NESTED LOOPS:
    Let Pᵢ = inner input, P₀ = outer input
    If Pᵢ is a single relation rᵢ with an index on join attribute:
        cost = P₀.cost + cost of A
    Else:
        cost = ∞  (can't use this algorithm)

Else (hash join, merge join, etc.):
    cost = P1.cost + P2.cost + cost of A
```

---

[🔝 Back to Top](#-table-of-contents)

---

## 11. Left-Deep Join Trees ⭐⭐⭐

### What is it?
A join tree where the **right-hand input** of every join is always a **base relation** (not an intermediate join result).

### Visual Comparison
```
LEFT-DEEP:                NON-LEFT-DEEP (Bushy):
      ⋈                          ⋈
     / \                        / \
    ⋈   r5                     ⋈   ⋈
   / \                        / \ / \
  ⋈   r4                    r1 r2 r3 r4
 / \
r1  r2   r3
```

### Why Left-Deep?
- Allows **pipelining** — inner relation result can be streamed without materializing
- Reduces optimization search space
- Most real-world optimizers consider **only** left-deep trees

---

[🔝 Back to Top](#-table-of-contents)

---

## 12. Interesting Sort Orders ⭐⭐⭐

### What is it?
A sort order of an intermediate result that could make a **subsequent operation cheaper**, even if producing that sorted order costs more now.

### Example
```
Query: (r1 ⋈ r2) ⋈ r3  (join attribute A is common to all)

Option 1: Use hash join for r1 ⋈ r2
    → Cheap, but output is UNSORTED
    → Must sort before merge-joining with r3

Option 2: Use merge join for r1 ⋈ r2
    → More expensive, but output is SORTED on A
    → Can directly merge-join with r3 → cheaper overall!
```

### Rule
When doing DP join order optimization, find the best plan for each subset **for each interesting sort order** — not just the globally cheapest.

---

[🔝 Back to Top](#-table-of-contents)

---

## 13. Heuristic Optimization ⭐⭐⭐⭐

### What is it?
Rule-based optimization that **typically** (but not always) improves query performance, used to reduce the number of plans that need cost-based evaluation.

### Key Heuristics

| Heuristic | Effect |
|---|---|
| **Perform selection early** | Reduces number of tuples → smaller relations to join |
| **Perform projection early** | Reduces number of attributes → smaller tuple size |
| **Most restrictive operations first** | Do the operation with smallest output first |

### How Optimizers Use Heuristics

```
Simple systems:    Use ONLY heuristics (no cost estimation)
Most systems:      Use heuristics to prune the search space,
                   then cost-based optimization on remaining plans
Oracle:            Heuristic optimization = repeatedly pick "best"
                   relation to join next, starting from each of n points
```

### Additional Optimizer Features
- **Optimization cost budget:** Stop optimizing if plan cost < optimization cost
- **Plan caching:** Reuse previously computed plan for same query (even with different constants)
- **Exhaustive enumeration** for expensive queries, simple heuristics for cheap ones

---

[🔝 Back to Top](#-table-of-contents)

---

## 14. Materialized Views ⭐⭐⭐⭐

### What is it?
A **view whose query result is precomputed and physically stored** on disk, rather than recomputed each time it is queried.

### Example
```sql
CREATE VIEW department_total_salary(dept_name, total_salary) AS
    SELECT dept_name, SUM(salary)
    FROM instructor
    GROUP BY dept_name;
```
If total salary by department is needed frequently → materializing this avoids repeated aggregation.

### Trade-offs

| Advantage | Disadvantage |
|---|---|
| Faster reads — result already computed | Storage space required |
| Useful for frequently repeated expensive queries | Must be kept up-to-date when base data changes |

### Using Materialized Views in Optimization
- If v = r ⋈ s is materialized and user queries r ⋈ s ⋈ t → rewrite as v ⋈ t
- Sometimes better to **replace** a materialized view with its definition if an index on the base table is available

---

[🔝 Back to Top](#-table-of-contents)

---

## 15. Incremental View Maintenance ⭐⭐⭐⭐

### What is it?
Updating a materialized view **incrementally** — computing only the changes caused by inserts/deletes — instead of recomputing from scratch.

**Notation:** iᵣ = tuples inserted into r, dᵣ = tuples deleted from r

### Rules by Operation

#### Join: v = r ⋈ s
```
Insert to r:  v_new = v_old ∪ (iᵣ ⋈ s)
Delete from r: v_new = v_old − (dᵣ ⋈ s)
```

#### Selection: v = σ_θ(r)
```
Insert to r:  v_new = v_old ∪ σ_θ(iᵣ)
Delete from r: v_new = v_old − σ_θ(dᵣ)
```

#### Projection: v = Π_A(r)
- Track a **count** for each tuple in the projection
- On insert: increment count (or add new tuple with count = 1)
- On delete: decrement count; if count = 0, remove tuple from view

#### Count Aggregation: v = A γ_count(B)(r)
```
On insert of iᵣ:
    For each tuple t in iᵣ:
        If group t.A exists in v → increment count by 1
        Else → add new tuple with count = 1

On delete of dᵣ:
    For each tuple t in dᵣ:
        Find group t.A in v → decrement count by 1
        If count becomes 0 → delete group from v
```

#### Sum Aggregation: v = A γ_sum(B)(r)
```
Same as count, but:
    → Add/subtract B value instead of 1
    → Also maintain count to detect empty groups (don't just check sum = 0!)
```
> ⚠️ **Why not check sum = 0?** Because positive and negative values can cancel out even when tuples still exist.

#### Average: Maintain sum and count separately, divide at query time

#### Min/Max:
- **Insertions:** Straightforward — compare new value with current min/max
- **Deletions:** Expensive — may need to scan all remaining tuples in the group to find new min/max

#### Set Intersection: v = r ∩ s
```
Insert to r:  Check if tuple exists in s; if yes, add to v
Delete from r: Remove from v if present
```

---

[🔝 Back to Top](#-table-of-contents)

---

## 16. Nested Subquery Optimization & Decorrelation ⭐⭐⭐

### What is it?
Transforming **correlated nested subqueries** into joins or semijoins to avoid slow repeated execution.

### The Problem: Correlated Evaluation
```sql
SELECT name
FROM instructor
WHERE EXISTS (
    SELECT *
    FROM teaches
    WHERE instructor.ID = teaches.ID AND teaches.year = 2019
);
```
- `instructor.ID` is a **correlation variable** — it changes for each outer tuple
- Naively, the subquery runs once for every instructor tuple → **very slow**

### Solution: Decorrelation
**Rewrite using join:**
```
Π_name ( instructor ⋈_(instructor.ID=teaches.ID ∧ teaches.year=2019) teaches )
```
⚠️ Problem: introduces duplicates (an instructor teaching 3 courses appears 3 times)

**Better: Use semijoin (⋉)**
```
Π_name ( instructor ⋉_(instructor.ID=teaches.ID ∧ teaches.year=2019) teaches )

Or:
Π_name ( instructor ⋉_instructor.ID=teaches.ID (σ_teaches.year=2019 (teaches)) )
```

**General rewrite rule:**
```
SELECT A FROM r1,...,rn
WHERE P1 AND EXISTS (SELECT * FROM s1,...,sm WHERE P2¹ AND P2²)

↓ Decorrelate to:

Π_A ( σ_P1(r1 × … × rn) ⋉_P2² σ_P2¹(s1 × … × sm) )

Where:
  P2¹ = predicates with NO correlation variables
  P2² = predicates WITH correlation variables
```

### NOT EXISTS → Anti-Semijoin (⋉̄)
```sql
WHERE NOT EXISTS (SELECT * FROM teaches WHERE instructor.ID = teaches.ID AND year=2019)

↓

Π_name ( instructor ⋉̄_(instructor.ID=teaches.ID ∧ teaches.year=2019) teaches )
```

### Scalar Aggregate Subqueries
```sql
SELECT name FROM instructor
WHERE 1 < (SELECT COUNT(*) FROM teaches WHERE instructor.ID = teaches.ID AND teaches.year = 2019)

↓ Decorrelate using groupby:

Π_name ( instructor ⋉_(instructor.ID=TID ∧ 1<cnt) (
    ID as TID γ_count(*) as cnt (σ_teaches.year=2019 (teaches))
))
```

---

[🔝 Back to Top](#-table-of-contents)

---

## 17. Semijoin & Anti-Semijoin ⭐⭐⭐

### What is it?
Special join variants used to correctly rewrite EXISTS/NOT EXISTS subqueries.

### Semijoin (⋉)
```
r ⋉_θ s

A tuple rᵢ appears n times in the result if:
  → It appears n times in r, AND
  → There exists at least one matching tuple sᵢ in s

(Right-hand tuples are NOT included in the output)
```

### Anti-Semijoin (⋉̄)
```
r ⋉̄_θ s

A tuple rᵢ appears in the result if:
  → It appears in r, AND
  → There is NO matching tuple in s

Used for NOT EXISTS queries
```

### Comparison
| Operation | SQL Equivalent | Keeps duplicates from r? |
|---|---|---|
| r ⋉ s | EXISTS | Yes |
| r ⋉̄ s | NOT EXISTS | Yes |
| r ⋈ s | JOIN | Yes — but may multiply tuples |

---

[🔝 Back to Top](#-table-of-contents)

---

## 18. Halloween Problem ⭐⭐

### What is it?
A subtle bug in update optimization where the **same tuple gets updated multiple times** in a single pass when using an index on the updated attribute.

### Example
```sql
UPDATE R SET A = 5 * A WHERE A > 10;
```
If an index on A is used:
1. Find tuple with A = 12 → update to A = 60
2. Index now points to A = 60 → finds it again (60 > 10) → updates to A = 300
3. Repeat infinitely! ❌

### Solutions
| Solution | Description | Drawback |
|---|---|---|
| **Always defer updates** | Collect all (old, new) pairs first, then apply in a second pass | Extra overhead even when unnecessary |
| **Defer only if required** | Immediate update if WHERE attrs ≠ SET attrs; defer otherwise | More complex to implement |

---

[🔝 Back to Top](#-table-of-contents)

---

## 19. Top-K Query Optimization ⭐⭐

### What is it?
Efficient execution of queries that retrieve only the **top K results** (ORDER BY + LIMIT).

### Example
```sql
SELECT * FROM r, s
WHERE r.B = s.B
ORDER BY r.A ASC
LIMIT 10;
```

### Approaches
| Approach | Description |
|---|---|
| **Indexed Nested Loops** | Use r as outer, iterate in index order on A — stop after 10 results |
| **Estimate cutoff H** | Estimate the Kth-smallest value H, add `AND r.A <= H` to WHERE clause; retry with larger H if < K results found |

---

[🔝 Back to Top](#-table-of-contents)

---

## 20. Importance Summary Table

| # | Topic | Exam Importance |
|---|---|---|
| 1 | Equivalence Rules & Expression Transformation | ⭐⭐⭐⭐⭐ |
| 2 | Expression Trees (Query Trees) | ⭐⭐⭐⭐⭐ |
| 6 | Selection Size Estimation | ⭐⭐⭐⭐⭐ |
| 7 | Join Size Estimation | ⭐⭐⭐⭐⭐ |
| 3 | Cost-Based Optimization Steps | ⭐⭐⭐⭐ |
| 5 | Statistical Information (nᵣ, V(A,r), etc.) | ⭐⭐⭐⭐ |
| 10 | Dynamic Programming / Join Order | ⭐⭐⭐⭐ |
| 13 | Heuristic Optimization | ⭐⭐⭐⭐ |
| 14 | Materialized Views | ⭐⭐⭐⭐ |
| 15 | Incremental View Maintenance | ⭐⭐⭐⭐ |
| 4 | Evaluation Plans | ⭐⭐⭐ |
| 8 | Size Estimation (Other Ops) | ⭐⭐⭐ |
| 9 | Histograms | ⭐⭐⭐ |
| 11 | Left-Deep Join Trees | ⭐⭐⭐ |
| 12 | Interesting Sort Orders | ⭐⭐⭐ |
| 16 | Decorrelation / Nested Subqueries | ⭐⭐⭐ |
| 17 | Semijoin & Anti-Semijoin | ⭐⭐⭐ |
| 18 | Halloween Problem | ⭐⭐ |
| 19 | Top-K Optimization | ⭐⭐ |

---

> 📖 **Reference:** Database System Concepts, 7th Edition — Silberschatz, Korth and Sudarshan  
> 🔗 [www.db-book.com](https://www.db-book.com)

---

*Good luck on your finals! Focus on the ⭐⭐⭐⭐⭐ topics first, then work your way down.* 🎯
