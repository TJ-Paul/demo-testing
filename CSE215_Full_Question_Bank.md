# CSE 215 — Databases | Question Bank

> **BUET | L-2/T-2 | 2017–2023**
> Compiled for quick revision. Each entry shows: **Year · Q# · Part · Short Description**.
> Questions are grouped by topic for easier navigation.

---

## 📑 Table of Contents

- [ACID Properties & Transactions](#-acid-properties--transactions)
- [Conflict Serializability & Precedence Graphs](#-conflict-serializability--precedence-graphs)
- [Locks, 2PL & Deadlocks](#-locks-2pl--deadlocks)
- [Timestamp-Based Concurrency Control](#-timestamp-based-concurrency-control)
- [Recoverable, ACR & Strict Schedules](#-recoverable-acr--strict-schedules)
- [Undo & Redo Logging](#-undo--redo-logging)
- [Checkpointing & Recovery](#-checkpointing--recovery)
- [Storage: Records, Blocks & Slotted Pages](#-storage-records-blocks--slotted-pages)
- [RAID](#-raid)
- [Indexing — Dense, Sparse & Secondary](#-indexing--dense-sparse--secondary)
- [B+ Trees](#-b-trees)
- [Hashing — Extensible & Linear](#-hashing--extensible--linear)
- [External Sorting & Sort-Merge](#-external-sorting--sort-merge)
- [Join Algorithms & Query Processing](#-join-algorithms--query-processing)
- [Query Optimization & Expression Trees](#-query-optimization--expression-trees)
- [Disk Scheduling](#-disk-scheduling)
- [ER Diagrams & Entity Modeling](#-er-diagrams--entity-modeling)
- [ISA Hierarchies & Weak Entities](#-isa-hierarchies--weak-entities)
- [ER to Relational Schema Conversion](#-er-to-relational-schema-conversion)
- [Relational Algebra](#-relational-algebra)
- [SQL — Queries](#-sql--queries)
- [SQL — DDL, Constraints & Views](#-sql--ddl-constraints--views)
- [PL/SQL — Triggers & Stored Procedures](#-plsql--triggers--stored-procedures)
- [Functional Dependencies & Attribute Closure](#-functional-dependencies--attribute-closure)
- [Normalization — 1NF to BCNF](#-normalization--1nf-to-bcnf)
- [XML & MapReduce](#-xml--mapreduce)

---

## 🔵 ACID Properties & Transactions

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2018-19 (Jan 2020) | Q1 | (a) | Explain ACID properties with an example; why they are essential for concurrent execution |
| 2020-21 | Q2 | (c) | Explain ACID properties of a transaction with an example |

---

## 🔵 Conflict Serializability & Precedence Graphs

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q2 | (a)(i) | Construct a schedule from a cinema seat-reservation scenario using standard notations |
| 2017-18 | Q2 | (a)(ii) | Define conflict serializable schedule; check it without a precedence graph |
| 2017-18 | Q2 | (a)(iii) | Check conflict serializability using precedence graph; find topological sort order |
| 2018-19 (Jan 2020) | Q1 | (b) | Construct concurrent schedule for two transactions; prove conflict serializability |
| 2019-20 | Q4 | (a) | Explain conflict serializability with example; build concurrent schedule for T1 & T2; draw precedence graph; find equivalent serial schedule |
| 2021-22 | Q7 | (c) | Sketch precedence graph for a 4-transaction schedule; determine conflict serializability; write equivalent serial schedule(s) |
| 2022-23 | Q1 | (c) | Build precedence graphs for schedules S1 and S2 involving 4 transactions; determine if conflict-serializable |

---

## 🔵 Locks, 2PL & Deadlocks

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q3 | (c) | Define deadlock in DB transactions with an example |
| 2017-18 | Q4 | (b) | Justify why two-phase locking is efficient for B+ tree index structures |
| 2019-20 | Q4 | (b) | Show and explain lock table entries (shared/exclusive) for a sequence of read/write operations across 4 transactions |
| 2020-21 | Q3 | (b) | Apply shared/exclusive/upgrade locks to a T1/T2/T3 operation sequence; show lock status at each step |
| 2021-22 | Q5 | (b) | Explain how two-phase locking is implemented using a lock table with figures and examples |
| 2022-23 | Q1 | (d) | Prove that a schedule satisfying strict 2PL avoids cascading rollback (ACR) |
| 2022-23 | Q3 | (c) | Build a deadlock schedule for two transactions using shared/exclusive lock upgrading; rewrite using update locks to prevent deadlock |
| 2022-23 | Q3 | (d) | For a 4-transaction schedule with given timestamps, determine "wound" or "wait" for each action under the wound-wait scheme |

---

## 🔵 Timestamp-Based Concurrency Control

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2022-23 | Q4 | (a) | Apply timestamp-based CC to a 4-transaction schedule; track RT/WT updates after each action; identify rollbacks |

---

## 🔵 Recoverable, ACR & Strict Schedules

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2022-23 | Q2 | (a) | Construct a concurrent schedule using the Thomas write rule; show equivalent serial schedule; discuss the problem with allowing it |
| 2022-23 | Q4 | (b) | Construct schedules that are: (i) recoverable but not ACR, (ii) serializable but not recoverable, (iii) ACR |

---

## 🔵 Undo & Redo Logging

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q4 | (a)(ii) | Describe recovery manager actions given a sequence of undo log records after a crash |
| 2022-23 | Q2 | (c) | Given undo-log for transactions T and U, determine recovery actions for crashes at three different last-disk-record points |
| 2022-23 | Q2 | (d) | For a given log, identify last record that must hit disk before updated A and B are flushed (undo); and before A and B are flushed (redo) |
| 2022-23 | Q2 | (b) | Give a two-pass hash-based algorithm for set difference R − S; analyze memory and I/O requirements |

---

## 🔵 Checkpointing & Recovery

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q4 | (a)(i) | Identify correct values for two "?" entries in a log with nonquiescent checkpoints; describe full recovery actions |
| 2019-20 | Q4 | (c) | Explain checkpoint in database recovery |
| 2020-21 | Q4 | (b) | Perform checkpoint after instruction 7 in a given log; run log-based recovery after crash at instruction 13 |
| 2022-23 | Q3 | (a) | Identify last log record that must reach disk before START CKPT and before END CKPT are written (nonquiescent checkpoint) |
| 2022-23 | Q3 | (b) | Identify oldest log record the recovery manager needs to scan in two different crash scenarios after a nonquiescent checkpoint |

---

## 🔵 Storage: Records, Blocks & Slotted Pages

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2020-21 | Q1 | (a) | Show storage of 5 student records in 3 blocks (4000 bytes each) using fixed-length record structure; no cross-block records |
| 2020-21 | Q1 | (b) | Insert two variable-length records into a slotted page; show structure after deleting one record |
| 2020-21 | Q1 | (c) | Show multi-table clustering for department + instructor relations; discuss efficient vs inefficient query types |
| 2021-22 | Q5 | (c) | Show file structure (free list) after deleting a record and inserting a new one; show slotted page with high-level block diagram |
| 2022-23 | Q8 | (c) | Draw record structure and slotted page layout for a given `course` table (fixed + variable-length fields) |

---

## 🔵 RAID

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (a) | Design RAID-6 scheme for 6 data disks using minimum redundant disks; describe recovery when 2 disks fail and when 3 disks fail |
| 2018-19 (Jan 2020) | Q4 | (a) | Storage, read, update, and full-disk recovery mechanism for RAID-5 with 4 disks |
| 2019-20 | Q1 | (b) | Compare block-level vs bit-level striping; show storage of 12 blocks in RAID-5 with 7 disks |
| 2019-20 | Q1 | (c) | Explain single-disk failure recovery in RAID-5 with an example |
| 2020-21 | Q4 | (c) | Show storage of 10 blocks in RAID-5 and RAID-6 across 6 disks; compare the two levels |
| 2021-22 | Q6 | (b) | Briefly describe the differences between RAID-5 and RAID-6 |

---

## 🔵 Indexing — Dense, Sparse & Secondary

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (c) | Whether dictionary-based indexing (one word per page) is dense or sparse — explain |
| 2018-19 (Jan 2020) | Q3 | (a) | Explain how two specific SELECT queries are executed using a given sparse index |
| 2018-19 (Jan 2020) | Q3 | (b) | Explain deletion of a range of records from a relation with a sparse index |
| 2018-19 (Jan 2020) | Q2 | (b) | Compute query cost for a conjunctive OR selection using secondary indices; explain the algorithm used |
| 2019-20 | Q2 | (a) | Build an ordered secondary index on attribute B for a given relation; explain insertion of a new tuple |
| 2020-21 | Q2 | (a) | Show index structure with concerned blocks after inserting two new tuples into a primary index (no overflow) |
| 2020-21 | Q3 | (c) | Compare primary index with secondary index using representative structure diagrams |
| 2021-22 | Q7 | (a) | Justify/criticize: secondary index scan can be worse than linear file scan without bitmap index scan |
| 2017-18 | Q2 | (c) | Give a scenario where a bitmap index is preferred over other index types |

---

## 🔵 B+ Trees

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q4 | (c) | Perform incremental insert (8, 9 then 24, 27) and delete (8, 9 then 24, 27) on a given B+ tree; draw state after each step |
| 2019-20 | Q2 | (b) | Construct B+ tree primary index (n=3) by incremental insertion in sorted order; insert one more key and show result |
| 2020-21 | Q2 | (b) | Build B+ tree (n=4) by inserting keys 90 down to 20; then delete 20, 30, 40, 50; draw states |
| 2021-22 | Q6 | (a) | Build an extendable hash structure for keys with h(x) = x mod 7 and bucket capacity 3; show final structure |
| 2022-23 | Q8 | (a) | Perform five sequential operations on a given degree-3 B+ tree (insert 315; insert 409 & 513; delete 456; delete 513; delete 982 & 895); draw state after each |
| 2022-23 | Q8 | (b) | Calculate height of a degree-5 B+ tree after sequentially inserting keys 1 to 100 |

---

## 🔵 Hashing — Extensible & Linear

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q3 | (a) | Insert records incrementally into an extensible hashing system using h(x) = x mod 1024; show state after each insertion |
| 2017-18 | Q3 | (b) | Insert same records into a linear hashing system; show state after each insertion |

---

## 🔵 External Sorting & Sort-Merge

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (d) | Steps of a one-pass algorithm for S − R where \|R\| < \|S\| |
| 2018-19 (Jan 2020) | Q2 | (a) | Diagram the sort of a 36-block relation with 4 memory buffers using external sort-merge; count total block transfers |
| 2019-20 | Q3 | (a) | Given relation size b_r and memory M, find runs, merge passes, block transfers, and seeks for three cases (N<M, N=M, N>M) |

---

## 🔵 Join Algorithms & Query Processing

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2022-23 | Q1 | (a) | Construct a 1.5-pass algorithm for left outer join R ⋈ S (R is smaller); compute memory and disk I/O cost |
| 2022-23 | Q1 | (b) | Compute I/O cost of natural join for block-nested loop, sort-based nested loop, and hash-based nested loop (B(R)=8000, B(S)=4000, M=101) |

---

## 🔵 Query Optimization & Expression Trees

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q2 | (b) | Express a nested SQL query (StarsIn / MovieStar) in relational algebra; draw logical query tree |
| 2019-20 | Q3 | (b) | Build an expression tree for a multi-join SQL; explain materialization vs pipeline evaluation |
| 2020-21 | Q8 | (b) | Given schema + SQL + equivalence rules, construct an optimized query plan expression tree with justification |

---

## 🔵 Disk Scheduling

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (e) | Calculate average time to read one block from a Megatron 747 disk given min/max seek, latency, transfer times |
| 2017-18 | Q3 | (c) | Schedule cylinder requests using the elevator algorithm; compute total service time |
| 2021-22 | Q8 | (c) | Given pending disk requests and head at track 71 moving upward, calculate average seek times for SCAN and C-SCAN |

---

## 🔵 ER Diagrams & Entity Modeling

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q5 | (a)(i)(ii) | Design ER diagram for a university: students, courses, faculty, office staff, semesters, coordinators; list entity sets and attributes |
| 2018-19 (Jan 2020) | Q13 | — | Design ER diagram for a website development department (websites, developers, frameworks, programming languages) |
| 2019-20 | Q5 | (a) | Complex university ER: professors, graduate students, departments, projects, supervisors, advisors, multi-phone; draw with all key and cardinality constraints |
| 2019-20 | Q6 | (a) | ER for an organization with employee ISA hierarchy (Technical/Non-technical, managed by a manager who is also an employee) |
| 2021-22 | Q2 | (a) | Design ER diagram for a cricket league (BPL) with teams, players, injuries, games, and scores |
| 2021-22 | Q2 | (b) | Design ER diagram for an organization with ISA hierarchy (Secretary, Engineer, Technician, Manager, Salaried, Hourly) |
| 2021-22 | Q5 | (a) | Interpret 10 true/false statements about a Teacher–teach–Course–enroll–Student ER diagram (participation, cardinality) |
| 2021-22 | Q5 | (b) | Design ER for a blog platform (users, bloggers ISA users, blogs, comments with optional rating) |
| 2021-22 | Q5 | (c) | Interpret arrows in a ternary Actor–Contract–Film–Studio relationship |
| 2022-23 | Q5 | (a) | Design four ER diagram portions for YouTube: user management, video hosting, commenting, and subscription system |

---

## 🔵 ISA Hierarchies & Weak Entities

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q5 | (b) | Convert Movies–Cartoons–MurderMysteries ISA hierarchy to relational schemas using three strategies |
| 2017-18 | Q5 | (c) | Define weak entity set and give an example |
| 2018-19 (Jan 2020) | Q11 | — | Differentiate strong and weak entities with examples; show how to design each in a relational schema |
| 2022-23 | Q6 | (b) | Give an example of a non-binary relationship; explain the issues that arise |

---

## 🔵 ER to Relational Schema Conversion

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2018-19 (Jan 2020) | Q12 | — | Convert the Production-Tracking ER diagram (ProductionUnits–Includes–Lot with RawMaterials) into a relational schema with PKs and referential integrity |
| 2019-20 | Q5 | (b) | Convert the university ER diagram from Q5(a) into a relational schema |
| 2019-20 | Q6 | (b) | Reduce a given ERD (entities A, B, C, D with relationships R1–R5) to the minimum set of relational schemas |
| 2021-22 | Q2 | (c) | Convert a given ER diagram (Courses–GivenBy–Depts with ISA Lab Courses) into a relational schema |
| 2022-23 | Q5 | (b) | Implement relational schemas for each of the four YouTube ER diagram portions |

---

## 🔵 Relational Algebra

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q2 | (b) | Express a nested SQL query in relational algebra; draw logical query tree (StarsIn / MovieStar) |
| 2017-18 | Q6 | (b) | Two relational algebra queries on Manufacturer/Laptop/Printer: Dell laptop models/speeds; manufacturers making ≥3 laptop models |
| 2018-19 (Jan 2020) | Q15 | — | Write relational algebra expression using Cartesian product to find savings-account customers at a specific branch with their loan amounts |
| 2018-19 (Jan 2020) | Q16 | — | Convert a given 3-table join SQL (customer, account, transaction) into a relational algebra expression |
| 2019-20 | Q7 | (a) | Five relational algebra queries on the standard university schema (Physics instructors, Watson building, Fall-not-Spring courses, higher-earning instructors, students with no 2022 courses) |
| 2020-21 | Q8 | (a) | Show with an example that π_a(R ∩ S) ≠ π_a(R) ∩ π_a(S) |
| 2020-21 | Q8 | (b) | Write relational algebra plan for a 3-table join SQL; convert to tree; optimize by pushing down selections and projections |
| 2020-21 | Q8 | (d) | For relations A (n_a tuples) and B (n_b tuples), give min/max tuple counts for A∩B, σ_c(A)−B, A∪B, and left outer join |
| 2021-22 | Q5 | (a) | Compute join size of r1 ⋈ r2 ⋈ r3 given tuple counts and join-column value counts |
| 2022-23 | Q6 | (a) | Three relational algebra queries on Room/Examinee/Evaluation/Absentee schema: non-sequential roll rooms, incorrectly evaluated scripts, mark-difference violations |

---

## 🔵 SQL — Queries

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q6 | (a) | Five SQL queries on Books/Author/Publisher schema: books by Hemingway, revenue by publisher, authors with ≥5 books since 1995, publisher with most authors, best-selling books vs pre-1990 same-publisher books |
| 2018-19 (Jan 2020) | Q5 | — | Find and fix a broken SQL query counting employees per manager; rewrite correctly |
| 2018-19 (Jan 2020) | Q6 | — | Query showing dept_id, job_id, first/last hire date, avg salary per (dept, job) group with avg salary > 3000, no nulls, ordered by dept |
| 2019-20 | Q7 | (b) | Five SQL queries on university schema: above-avg salary instructors, courses in both semesters, students who took all of John Doe's courses, dept student counts, lowest avg salary dept |
| 2020-21 | Q5 | (a)(i) | SQL query returning topics discussed by Pori+Himu but not by Pori+Misir Ali |
| 2020-21 | Q5 | (a)(ii) | SQL query returning count of topics discussed by more than 10 user-pairs |
| 2020-21 | Q5 | (b)(ii) | SQL query finding all papers with fewer than 3 reviewers (including papers with none) |
| 2020-21 | Q5 | (b)(iii) | SQL query finding reviewer(s) with the most papers assigned |
| 2021-22 | Q1 | (a) | Five SQL queries on Toys/Client/Request schema: clients with no requests, toys heavier than color-average, unavailable requested toys, age-limit violations, most popular toy |

---

## 🔵 SQL — DDL, Constraints & Views

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2019-20 | Q8 | (a) | What is the difference between referential integrity and FK constraint; three UPDATE/DELETE policies and which suits each |
| 2019-20 | Q6 | (c) | Define materialized view; explain associated problems; describe restrictions for allowing updates on materialized views |
| 2020-21 | Q5 | (b)(i) | Declare Paper/Reviewer/Reviews tables with keys and referential integrity (cascade/null on delete, cascade on update, reject) |
| 2020-21 | Q5 | (c) | Replace a UNIQUE constraint with an equivalent CHECK constraint |
| 2021-22 | Q1 | (b) | Two DML queries on Product/PC/Laptop schema: bulk insert laptops from PCs, delete laptops whose maker doesn't make PCs |
| 2021-22 | Q3 | (a) | Show SQL command to create a duplicate of a table with data; show how to copy schema only |
| 2021-22 | Q4 | (b) | Write constraints for six rules on Product/PC/Laptop/Printer schema (negative values, model existence, screen-size vs disk, manufacturer restrictions) |
| 2022-23 | Q7 | (b)(i) | Write a SQL view for total production cost per food item (ingredient cost for simple items, containing-item cost for packages) |
| 2022-23 | Q7 | (b)(ii) | Write a SQL query for monthly profit per food item using the production-cost view |

---

## 🔵 PL/SQL — Triggers & Stored Procedures

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q8 | (a) | Write a trigger on MovieExec to prevent average net worth from dropping below $50,000 |
| 2017-18 | Q8 | (b) | Write a stored procedure counting black-and-white movies for a given studio and year |
| 2018-19 (Jan 2020) | Q7 | — | Write IncreaseOrDecrease procedure: increase salary 10% if below dept avg but above all-other-depts avg, else decrease 5% |
| 2020-21 | Q8 | (c) | Write triggers for Product/Laptop schema: (i) prevent negative attribute values; (ii) cascade delete from Product when a Laptop is deleted |

---

## 🔵 Functional Dependencies & Attribute Closure

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q7 | (a) | Steps to compute attribute closure; find {A,B}⁺ for a given set of FDs over A,B,C,D,E,F |
| 2019-20 | Q8 | (d) | Write the six closure rules (Armstrong's axioms + derived) with examples |
| 2021-22 | Q3 | (b) | Find all nontrivial FDs for R(A,B,C,D,E) with given FDs; find all keys; find all superkeys that are not keys |
| 2021-22 | Q7 | (a) | Find all functional dependencies that hold on a given Name/Address/ZipCode table; write minimal set |
| 2020-21 | Q7 | (c) | For R(A,B,C,D) with FDs AB→C, C→D, D→A: find all nontrivial FDs (single RHS), all keys, all superkeys that are not keys |

---

## 🔵 Normalization — 1NF to BCNF

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q7 | (b) | Given address-book schema R(SSN, Name, PhoneType, PhoneNumber): find keys, check BCNF, decompose into BCNF |
| 2017-18 | Q7 | (c) | Give a relation in 3NF but not in BCNF; define multivalued dependency |
| 2018-19 (Jan 2020) | Q8 | — | Normalize StaffPropertyInspection table to 2NF: find candidate keys, PK, FDs, 1NF, 2NF |
| 2018-19 (Jan 2020) | Q14 | — | Agree/disagree: a table in 3NF may fail BCNF; provide an example to validate |
| 2019-20 | Q8 | (b) | Define BCNF and 3NF; major difference; how to decompose R into BCNF given a violating FD |
| 2019-20 | Q8 | (c) | Check if decomposing R(A,B,C,D,E) into (A,B,C) and (A,D,E) is lossless given a set of FDs |
| 2021-22 | Q3 | (c) | Decompose R(A,B,C,D,E) with FDs AB→C, DE→C, B→D into BCNF; show final normalized schema with all keys |
| 2021-22 | Q7 | (b) | Decompose the relation from Q7(a) into BCNF; show work and final schema with keys |
| 2022-23 | Q7 | (a) | Given a restaurant report table (food items, ingredients, packages, sales), normalize to 1NF, 2NF, 3NF, and BCNF |
| 2021-22 | Q6 | (c) | Compare dirty reads, read committed, and repeatable reads isolation levels with illustrative examples |

---

## 🔵 XML & MapReduce

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q8 | (c) | Describe the structure of a given STARS DTD; write a sample XML file conforming to it |
| 2017-18 | Q8 | (d) | Briefly describe the MapReduce framework |

---

*Last updated: 2026 | Source: CSE 215 Final Exam Papers, 2017-18 through 2022-23*
