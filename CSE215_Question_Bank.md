# CSE 215 — Databases | Question Bank

> **Course:** CSE 215 (Databases) — BUET L-2/T-2
> **Purpose:** Quick-revision reference. Questions are summarized, not reproduced verbatim.

---

## Table of Contents

- [Section A — Storage, Indexing, Query Processing, Transactions](#section-a--storage-indexing-query-processing-transactions)
  - [2017-18](#2017-18-section-a)
  - [2018-19 (Jan 2020 Term)](#2018-19-jan-2020-term-section-a)
  - [2019-20](#2019-20-section-a)
  - [2020-21](#2020-21-section-a)
  - [2021-22](#2021-22-section-a)
  - [2022-23](#2022-23-section-a)
- [Section B — ER Modeling, SQL, Normalization, B+ Trees](#section-b--er-modeling-sql-normalization-b-trees)
  - [2017-18](#2017-18-section-b)
  - [2018-19 (Jan 2020 Term)](#2018-19-jan-2020-term-section-b)
  - [2019-20](#2019-20-section-b)
  - [2020-21](#2020-21-section-b)
  - [2021-22](#2021-22-section-b)
  - [2022-23](#2022-23-section-b)

---

## Section A — Storage, Indexing, Query Processing, Transactions

---

### 2017-18 Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | RAID | Design a RAID-6 scheme for 6 data disks using minimum redundant disks. |
| 1 | b | RAID Recovery | Describe recovery when 2 disks fail; when 3 disks fail simultaneously. |
| 1 | c | Indexing | Whether dictionary-based indexing (one word per page) is dense or sparse. |
| 1 | d | One-pass Algorithm | Steps of a one-pass algorithm for S − R where \|R\| < \|S\|. |
| 1 | e | Disk I/O | Calculate average time to read one block from a Megatron 747 disk given min/max seek, latency, transfer times. |
| 2 | a | Schedules & Serializability | Build a schedule from a cinema seat-reservation scenario; check conflict serializability with and without precedence graph; find topological sort order. |
| 2 | b | Relational Algebra | Express a nested SQL query (StarsIn / MovieStar) in relational algebra; draw logical query tree. |
| 2 | c | Bitmap Index | Give a scenario where a bitmap index is preferred over other index types. |
| 3 | a | Extensible Hashing | Insert records incrementally into an extensible hashing system using h(x) = x mod 1024; show state after each insertion. |
| 3 | b | Linear Hashing | Insert same records into a linear hashing system; show state after each insertion. |
| 3 | c | Disk Scheduling | Schedule cylinder requests using the elevator algorithm; compute total service time. |
| 3 | d | Deadlock | Define deadlock in DB transactions with an example. |
| 4 | a | Undo Logging & Recovery | Given a crash scenario with undo log and nonquiescent checkpoints, identify correct checkpoint entries and describe recovery actions. |
| 4 | b | 2PL on B+ Tree | Justify why two-phase locking is efficient for B+ tree index structures. |
| 4 | c | B+ Tree Operations | Perform incremental insert (8, 9 then 24, 27) and delete (8, 9 then 24, 27) on a given B+ tree; draw state after each step. |

---

### 2018-19 (Jan 2020 Term) Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | ACID Properties | Explain ACID with an example; why they are essential for concurrency. |
| 1 | b | Conflict Serializability | Construct a concurrent schedule for two given transactions; prove conflict serializability. |
| 2 | a | External Sort-Merge | Diagram the sort of a 36-block relation with 4 memory buffers; count total block transfers. |
| 2 | b | Query Cost Estimation | Compute query cost for a conjunctive OR selection using secondary indices; explain the algorithm used. |
| 3 | a | Sparse Index Lookup | Explain how two specific SELECT queries are executed using a given sparse index. |
| 3 | b | Sparse Index Deletion | Explain deletion of a range of records from a relation with a sparse index. |
| 4 | a | RAID-5 | Storage, read, update, and full-disk recovery mechanism for RAID-5 with 4 disks. |
| 4 | b | Slotted Page Structure | Show slotted page organization after inserting mixed-size tuples from three different relations. |

---

### 2019-20 Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | Disk Access | Explain disk access time and its implications in DBMS. |
| 1 | b | RAID-5 | Compare block-level vs bit-level striping; show storage of 12 blocks in RAID-5 with 7 disks. |
| 1 | c | RAID-5 Recovery | Explain single-disk failure recovery in RAID-5 with an example. |
| 2 | a | Secondary Index | Build an ordered secondary index on attribute B for a given relation; explain insertion of a new tuple. |
| 2 | b | B+ Tree Construction | Construct a B+ tree primary index (n=3) by incremental insertion in sorted order; insert one more key and show result. |
| 3 | a | External Sort-Merge | Given relation size b_r and memory M, find runs, merge passes, block transfers, and seeks for three cases (N<M, N=M, N>M). |
| 3 | b | Expression Tree & Evaluation | Build an expression tree for a multi-join SQL; explain materialization vs pipeline evaluation. |
| 4 | a | Conflict Serializability | Explain with example; construct a concurrent schedule for two given transactions; draw precedence graph; find equivalent serial schedule. |
| 4 | b | Lock Table | Show lock table entries step by step for a sequence of read/write operations across 4 transactions. |
| 4 | c | Checkpoint | Explain checkpoint in database recovery. |

---

### 2020-21 Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | Fixed-Length Records | Show storage of 5 student records in 3 blocks of 4000 bytes using fixed-length structure (no cross-block records). |
| 1 | b | Slotted Page Structure | Insert two variable-length records, show slotted page; then show state after deleting one record. |
| 1 | c | Multi-table Clustering | Show multi-table clustering for department + instructor relations; discuss efficient and inefficient query types. |
| 2 | a | Dense Index & Overflow | Show index structure after inserting new tuples into a full primary index (no overflow allowed). |
| 2 | b | B+ Tree Operations | Build B+ tree (n=4) by inserting keys 90 down to 20; then delete 20, 30, 40, 50. |
| 2 | c | ACID | Explain ACID properties with an example. |
| 3 | a | Query Cost (Conjunctive Selection) | Find worst-case cost of processing a conjunctive AND selection using a single index; explain execution method. |
| 3 | b | Locking | Apply shared/exclusive/upgrade locks to a given sequence of T1/T2/T3 operations; show lock status at each step. |
| 3 | c | Primary vs Secondary Index | Compare primary and secondary index with representative structure diagrams. |
| 4 | a | Buffer / Disk I/O Model | Show memory buffer ↔ transaction work area ↔ disk relationship; explain read and write for a transaction. |
| 4 | b | Redo Logging & Checkpoint | Perform a checkpoint after instruction 7 in a given log; run log-based recovery after a crash at instruction 13. |
| 4 | c | RAID-5 & RAID-6 | Show storage of 10 blocks in RAID-5 and RAID-6 across 6 disks; compare the two levels. |

---

### 2021-22 Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | SQL / Toys DB | Five SQL queries on Toys/Client/Request schema: clients with no requests, toys heavier than color-average, unavailable requested toys, age-limit violations, most popular toy. |
| 1 | b | DML Updates | Two DML queries on Product/PC/Laptop schema: bulk insert laptops from PCs, delete laptops whose maker doesn't make PCs. |
| 2 | a | ER Diagram (BPL) | Design ER diagram for a cricket league (BPL) with teams, players, injuries, games, and scores. |
| 2 | b | ER Diagram (Employee ISA) | Design ER diagram for an organization with ISA hierarchy (Secretary, Engineer, Technician, Manager, Salaried, Hourly); convert to relational schemas. |
| 2 | c | ER to Schema | Convert a given ER diagram (Courses–GivenBy–Depts with ISA Lab Courses) into a relational schema. |
| 3 | a | SQL (duplicate table) | Show SQL to create a duplicate of a table with data; show how to copy schema only. |
| 3 | b | Functional Dependencies & Keys | Find all nontrivial FDs for R(A,B,C,D,E) with given FDs; find all keys; find all superkeys that are not keys. |
| 3 | c | BCNF Decomposition | Decompose R(A,B,C,D,E) with FDs AB→C, DE→C, B→D into BCNF; show final normalized schema with all keys. |
| 4 | a | UNIQUE vs PRIMARY KEY | Difference between UNIQUE and PRIMARY KEY constraints. |
| 4 | b | Constraints & Triggers | Write constraints (as assertions or triggers) for six rules on Product/PC/Laptop/Printer schema. |
| 4 | c | Tuple Count (Relational Algebra) | For two relations with n_a and n_b tuples, give min/max tuple counts for intersection, selection-minus, union, and left outer join. |

---

### 2022-23 Section A

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 1 | a | One-and-a-half Pass Join | Construct a 1.5-pass algorithm for left outer join R ⋈ S (R is smaller); compute memory and disk I/O cost. |
| 1 | b | Join Algorithm I/O Cost | Compute I/O cost of natural join for block-nested loop, sort-based nested loop, and hash-based nested loop (B(R)=8000, B(S)=4000, M=101). |
| 1 | c | Conflict Serializability | Build precedence graphs for two given schedules S1 and S2 involving 4 transactions; determine if conflict-serializable. |
| 1 | d | Strict 2PL & ACR | Prove that a schedule satisfying strict 2PL avoids cascading rollback (ACR). |
| 2 | a | Thomas Write Rule | Construct a concurrent schedule using the Thomas write rule; show equivalent serial schedule; discuss the problem with allowing it. |
| 2 | b | Two-pass Hash Set Difference | Give a two-pass hash-based algorithm for R − S; analyze memory and I/O requirements. |
| 2 | c | Undo Log Recovery | Given undo-log for transactions T and U, determine recovery actions for crashes at three different last-disk-record points. |
| 2 | d | Undo vs Redo Logging Rules | For a given log sequence, identify the last log record that must be on disk before updated values A and B are written (undo); same question for redo logging. |
| 3 | a | Nonquiescent Checkpoint | Given a long undo-log, identify the last log record that must reach disk before START CKPT and before END CKPT are written. |
| 3 | b | Recovery After Crash | For the same log, identify the oldest log record the recovery manager needs to scan in two different crash scenarios. |
| 3 | c | Deadlock via Lock Upgrading | Build a deadlock schedule for two transactions using shared/exclusive lock upgrading; then rewrite using update locks to prevent deadlock. |
| 3 | d | Wound-Wait Avoidance | For a 4-transaction schedule with given timestamps, determine "wound" or "wait" for each action under the wound-wait scheme. |
| 4 | a | Timestamp-Based CC | Apply timestamp-based concurrency control to a 4-transaction schedule; track RT/WT updates; identify rollbacks. |
| 4 | b | Recoverable & ACR Schedules | Construct schedules that are: (i) recoverable but not ACR, (ii) serializable but not recoverable, (iii) ACR. |
| 4 | c | Wait-for Graph & Deadlock | Build wait-for graph for a 4-transaction schedule with shared/exclusive locks; detect deadlock; rollback highest-numbered transaction and show resulting graph. |

---

## Section B — ER Modeling, SQL, Normalization, B+ Trees

---

### 2017-18 Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | a | ER Diagram (University) | Design ER diagram for a university: students, courses, faculty, office staff, semesters, coordinators. |
| 5 | b | ISA Hierarchy Conversion | Convert Movies–Cartoons–MurderMysteries ISA hierarchy to relational schemas using three strategies. |
| 5 | c | Weak Entity | Define weak entity set and give an example. |
| 6 | a | SQL (Books DB) | Five SQL queries on Books/Author/Publisher schema: books by Hemingway, revenue by publisher (1980–90), authors with ≥5 books since 1995, publisher with most authors, books selling more than any pre-1990 book by the same publisher. |
| 6 | b | Relational Algebra (Laptops) | Two relational algebra queries on Manufacturer/Laptop/Printer: Dell laptop models/speeds; manufacturers making ≥3 laptop models. |
| 7 | a | Attribute Closure | Steps to compute attribute closure; find {A,B}⁺ for a given set of FDs over A,B,C,D,E,F. |
| 7 | b | BCNF Decomposition | Given address-book schema R(SSN, Name, PhoneType, PhoneNumber) with FDs: find keys, check BCNF, decompose if needed. |
| 7 | c | 3NF vs BCNF & MVD | Give a relation in 3NF but not BCNF; define multivalued dependency. |
| 8 | a | Trigger (Avg Net Worth) | Write a trigger on MovieExec to prevent average net worth from dropping below $50,000. |
| 8 | b | Stored Procedure | Write a stored procedure counting black-and-white movies for a given studio and year. |
| 8 | c | XML / DTD | Describe the structure of a given STARS DTD; write a sample XML file conforming to it. |
| 8 | d | MapReduce | Briefly describe the MapReduce framework. |

---

### 2018-19 (Jan 2020 Term) Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | — | SQL (HR Schema) | Fix a broken SQL query that counts employees per manager; rewrite correctly. |
| 6 | — | SQL (HR Schema) | Write a query showing dept_id, job_id, first/last hire date, avg salary per (dept, job) group with avg salary > 3000, no nulls, ordered by dept. |
| 7 | — | PL/SQL Procedure | Write IncreaseOrDecrease procedure: increase salary 10% if below dept avg but above all-other-depts avg, else decrease 5%; print action taken. |
| 8 | — | Normalization (2NF) | Normalize StaffPropertyInspection table to 2NF: find candidate keys, primary key, FDs, 1NF, 2NF. |
| 9 | — | DBMS Basics | Requirements of an ideal DBMS; define entity and attribute with examples. |
| 10 | — | Bad Design | Explain how redundancy and incompleteness lead to bad database design with examples. |
| 11 | — | Strong vs Weak Entity | Differentiate strong and weak entities with examples; show how to design each in a relational schema. |
| 12 | — | ERD to Schema | Convert the given Production-Tracking ER diagram (ProductionUnits–Includes–Lot, with RawMaterials) into a relational schema with PKs and referential integrity. |
| 13 | — | ER Diagram (Website Dev) | Design an ER diagram for a website development department (websites, developers, frameworks, programming languages). |
| 14 | — | 3NF vs BCNF | Agree/disagree: a table in 3NF may fail BCNF; provide an example to validate. |
| 15 | — | Relational Algebra (Bank) | Write a relational algebra expression using Cartesian product to find customers with savings accounts at a specific branch and their loan amounts. |
| 16 | — | Relational Algebra from SQL | Convert a given 3-table join SQL (customer, account, transaction) into a relational algebra expression. |

---

### 2019-20 Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | a | ER Diagram (University) | Complex university ER: professors, graduate students, departments, projects, supervisors, advisors, multi-phone. Draw ER with all key and cardinality constraints. |
| 5 | b | ER to Relational Schema | Convert the university ER diagram from 5(a) into a relational schema. |
| 6 | a | ER Diagram (Employee ISA) | ER for an organization with employee ISA hierarchy (Technical/Non-technical, managed by manager who is also an employee); convert to two different relational schemas. |
| 6 | b | ERD Reduction | Reduce a given ERD (entities A, B, C, D with relationships R1–R5) to the minimum set of relational schemas. |
| 6 | c | Materialized View | Define materialized view; explain associated problems; describe restrictions for allowing updates. |
| 7 | a | Relational Algebra (University) | Five relational algebra queries on the standard university schema (Physics instructors, Watson building, Fall-not-Spring courses, higher earners, students with no 2022 courses). |
| 7 | b | SQL (University) | Five SQL queries on the same schema (above-avg salary instructors, courses in both semesters, students who took all of John Doe's courses, dept student counts, lowest avg salary dept). |
| 8 | a | Referential Integrity | Difference between referential integrity and FK constraint; three UPDATE/DELETE policies and which suits each operation. |
| 8 | b | BCNF vs 3NF | Define BCNF and 3NF; major difference; how to decompose R into BCNF given a violating FD. |
| 8 | c | Lossless Decomposition | Check if decomposing R(A,B,C,D,E) into (A,B,C) and (A,D,E) is lossless given a set of FDs. |
| 8 | d | FD Closure Rules | Write down the six rules (Armstrong's axioms + derived) to find closure of a set of FDs, with examples. |

---

### 2020-21 Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | a | SQL (Discussion Table) | Two SQL queries: topics discussed by Pori+Himu but not Pori+Misir Ali; count topics discussed by >10 user-pairs. |
| 5 | b | DDL + SQL (Conference DB) | Declare Paper/Reviewer/Reviews tables with keys and referential integrity; query papers with <3 reviewers (including paperless); query reviewer(s) with most papers. |
| 5 | c | CHECK Constraint | Replace a UNIQUE constraint with an equivalent CHECK constraint. |
| 6 | a | ERD Interpretation | Given a Teacher–teach–Course–enroll–Student ER diagram, determine which of 10 statements are true (participation, cardinality, entity vs relationship). |
| 6 | b | ER Diagram (Blog Platform) | Design ER for a blog platform (users, bloggers ISA users, blogs, comments with optional rating); write CREATE TABLE statements with keys and FKs. |
| 6 | c | Multi-way Relationship | Interpret arrows in a ternary Actor–Contract–Film–Studio relationship. |
| 7 | a | Functional Dependencies | Find minimal set of FDs that hold on a given Name/Address/ZipCode table. |
| 7 | b | BCNF Decomposition | Decompose the relation from 7(a) into BCNF; show work and final schema with keys. |
| 7 | c | FDs, Keys, Superkeys | For R(A,B,C,D) with FDs AB→C, C→D, D→A: find all nontrivial FDs (single RHS), all keys, all superkeys that are not keys. |
| 8 | a | Relational Algebra Property | Show with an example that π_a(R ∩ S) ≠ π_a(R) ∩ π_a(S). |
| 8 | b | Query Optimization | Write a relational algebra plan for a 3-table join SQL; convert to tree; optimize by pushing down selections and projections. |
| 8 | c | Triggers | Write triggers for Product/Laptop schema: (i) prevent negative attribute values; (ii) cascade delete from Product when a Laptop is deleted. |
| 8 | d | Tuple Count (RA Expressions) | For relations A (n_a tuples) and B (n_b tuples), give min/max tuple counts for A∩B, σ_c(A)−B, A∪B, and left outer join A ⋉ B. |

---

### 2021-22 Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | a | Join Size Estimation | Compute size of r1 ⋈ r2 ⋈ r3 given tuple counts and join column value counts for three relations. |
| 5 | b | Two-Phase Locking | Explain how 2PL is implemented using a lock table with figures and examples. |
| 5 | c | Fixed-Length Records & Slotted Page | Show file structure after deleting one record and inserting a new one (free list); show slotted page structure with only record blocks visible. |
| 6 | a | Extendable Hashing | Build an extendable hash structure for keys {2,3,5,7,11,17,19,23} with h(x)=x mod 7 and bucket capacity 3; show final structure. |
| 6 | b | RAID-5 vs RAID-6 | Briefly describe the differences between RAID-5 and RAID-6. |
| 6 | c | Isolation Levels | Compare dirty reads, read committed, and repeatable reads with illustrative examples. |
| 7 | a | Bitmap Index & Table Partitioning | Justify/criticize: secondary index scan can be worse than linear file scan without bitmap index scan; explain table partitioning for a large Course Registration table. |
| 7 | b | Query Optimization | Sketch precedence graph for a 4-transaction schedule; check conflict serializability; write equivalent serial schedules. |
| 8 | a | Query Processing (Aggregation/Pipelining) | Describe how aggregation and set operations are processed; discuss whether pipelining can improve performance. |
| 8 | b | Optimized Query Plan | Given schema + SQL + equivalence rules, construct an optimized query plan expression tree with justification. |
| 8 | c | Disk Scheduling (SCAN & C-SCAN) | Given pending disk requests and head at track 71 moving upward, calculate average seek times for SCAN and C-SCAN algorithms. |

---

### 2022-23 Section B

| Q | Part | Topic | Description |
|---|------|-------|-------------|
| 5 | a | ER Diagram (YouTube) | Design four ER diagram portions for YouTube: user management, video hosting, commenting, and subscription system. Mark PKs and add suitable attributes. |
| 5 | b | Relational Schema from ERD | Implement relational schemas for each of the four YouTube ER diagram portions from 5(a). |
| 6 | a | Relational Algebra (Exam DB) | Three relational algebra queries on Room/Examinee/Evaluation/Absentee schema: find rooms with non-sequential roll numbers, find incorrectly evaluated scripts (not exactly 2 examiners), find (Roll No, Question No) pairs where two examiners' marks differ by >2. |
| 6 | b | Non-Binary Relationship | Give an example of a non-binary relationship; explain the issues that arise. |
| 7 | a | Normalization (Restaurant DB) | Given a restaurant report table (food items, ingredients, packages, sales), create a relational schema, identify FDs, and normalize to 1NF, 2NF, 3NF, and BCNF. |
| 7 | b | SQL View & Profit Query | (i) Write a SQL view for total production cost per food item (ingredients cost for simple items, containing items cost for packages). (ii) Write a SQL query for monthly profit per food item using the view. |
| 8 | a | B+ Tree Operations | Perform five sequential operations (insert 315; insert 409 & 513; delete 456; delete 513; delete 982 & 895) on a given degree-3 B+ tree; draw state after each. |
| 8 | b | B+ Tree Height | Calculate height of a degree-5 B+ tree after sequentially inserting keys 1 to 100. |
| 8 | c | Slotted Page Record Structure | Draw the record structure and slotted page layout for a given `course` table (fixed + variable-length fields). |

---

*Last updated: April 2026 — covers exam papers 2017-18 through 2022-23.*
