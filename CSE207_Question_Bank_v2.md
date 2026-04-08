# CSE 207 — Data Structures & Algorithms II
## Question Bank (2017–18 to 2022–23)

> **Source:** BUET L-2/T-2 Term Final Examinations  
> **Topics:** Flow / Max-flow · Red-Black Tree · AVL Tree · BFS & DFS · SSSP · APSP

---

## Table of Contents

1. [Flow / Max-flow](#1-flow--max-flow)
   - [Ford-Fulkerson & Edmonds-Karp](#11-ford-fulkerson--edmonds-karp)
   - [Min-cut Theorem](#12-min-cut-theorem)
   - [Bipartite Matching](#13-bipartite-matching)
   - [Application Problems](#14-application-problems)
2. [Red-Black Tree](#2-red-black-tree)
   - [Properties & Proofs](#21-properties--proofs)
   - [Insertion](#22-insertion)
   - [Deletion](#23-deletion)
   - [Conceptual](#24-conceptual)
3. [AVL Tree](#3-avl-tree)
   - [Properties & Proofs](#31-properties--proofs)
   - [Rotations & Balancing](#32-rotations--balancing)
   - [Insertion](#33-insertion)
   - [Fibonacci / Node Count](#34-fibonacci--node-count)
4. [BFS, DFS & MST](#4-bfs-dfs--mst)
   - [BFS for Shortest Paths](#41-bfs-for-shortest-paths)
   - [DFS & Traversal Applications](#42-dfs--traversal-applications)
   - [MST — Kruskal & Prim](#43-mst--kruskal--prim)
5. [SSSP](#5-sssp)
   - [Dijkstra's Algorithm](#51-dijkstras-algorithm)
   - [Bellman-Ford](#52-bellman-ford)
   - [Miscellaneous](#53-miscellaneous)
6. [APSP](#6-apsp)
   - [Johnson's Algorithm](#61-johnsons-algorithm)
   - [Floyd-Warshall / Warshall](#62-floyd-warshall--warshall)
   - [Variants](#63-variants)

---

## 1. Flow / Max-flow

### 1.1 Ford-Fulkerson & Edmonds-Karp

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q2(b) | 10 | Apply Ford-Fulkerson on a given network; find max-flow and min-cut |
| 2017–18 | Q2(c) | 10 | Describe Edmonds-Karp (min path length augmentation); explain time complexity improvement |
| 2018–19 | Q2(b) | 15 | Find max-flow by drawing residual networks step by step; identify min-cut |
| 2022–23 | Q3(c) | 5 | State the Edmonds-Karp optimization for Ford-Fulkerson |

### 1.2 Min-cut Theorem

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q3(b) | 8 | Prove the max-flow min-cut theorem |

### 1.3 Bipartite Matching

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q3(b) | 6+6 | Formulate max bipartite matching; give two real-life examples |
| 2022–23 | Q3(c) | 10 | Develop a solution for max bipartite matching |

### 1.4 Application Problems

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q8(b) | 23 | Ad-hoc wireless backup sets — reduce to max-flow, prove correctness, analyze running time |
| 2020–21 | Q3(a) | 10 | Find the single edge whose capacity increase maximally boosts network flow |
| 2020–21 | Q4(a) | 15 | Determine edge connectivity of an undirected graph using max-flow on at most \|V\| networks |
| 2021–22 | Q4(a) | 8 | Define the max-flow problem |
| 2021–22 | Q4(b) | 12+15 | Car-parking assignment — formulate as max-flow/min-cut; minimize total travel cost |
| 2022–23 | Q1(b) | 23 | Peculiar city roads (gender-restricted types) — maximize renovated roads while keeping connectivity |

---

## 2. Red-Black Tree

### 2.1 Properties & Proofs

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(a) | 12 | Prove a height-balanced tree with n nodes has O(log n) height |
| 2021–22 | Q2(c) | 15 | State RBT properties; derive height bound h ≤ 2lg(n+1) |

### 2.2 Insertion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(b) | 15 | Insert 11 into a given RBT; show all steps |
| 2019–20 | Q4(c) | 15 | Insert 11 into a given RBT; show all intermediate steps |
| 2022–23 | Q4(c) | 15 | Write RBT insertion pseudocode; show all rotation/recoloring cases; compare with AVL |

### 2.3 Deletion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2020–21 | Q6(b) | 5+15 | Can RBT be fixed after deletion without rotation? Delete key=150 and show steps |

### 2.4 Conceptual

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q4(a)-i | 5 | Why is a newly inserted node colored red, not black? |
| 2018–19 | Q4(a)-ii | 5 | Does inserting then immediately deleting a node change the tree? |
| 2018–19 | Q4(a)-iii | 5 | What is the ratio of longest to shortest path in an RBT? |
| 2020–21 | Q7(d) | 5 | Pros and cons of inserting nodes as black by default |
| 2017–18 | Q5(c) | 4 | One advantage of AVL over RBT, and one advantage of RBT over AVL |

---

## 3. AVL Tree

### 3.1 Properties & Proofs

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(a) | 12 | Prove height-balanced tree with n nodes has O(log n) height |
| 2022–23 | Q4(b) | 12 | State AVL properties; prove it is a balanced BST |
| 2019–20 | Q4(b) | 12 | Prove or disprove two statements about AVL path lengths and minimum node counts |

### 3.2 Rotations & Balancing

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q3(a) | 15 | Types of rotations; how rotation restores balance; max height of 10-node AVL |
| 2021–22 | Q2(b) | 12 | Demonstrate balancing procedure when the lowest violating node is left-heavy |

### 3.3 Insertion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2020–21 | Q7(a) | 5+5 | Insert key=20 then key=68 into a given AVL tree; show all steps |

### 3.4 Fibonacci / Node Count

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(d) | 4 | Given i-th and (i+2)-th Fibonacci numbers, find minimum nodes in AVL tree of height (i−1) |

---

## 4. BFS, DFS & MST

### 4.1 BFS for Shortest Paths

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q8(a) | 5 | Adapt BFS for SSSP on graphs with unequal edge weights |
| 2019–20 | Q5(a) | 13 | Reduce weighted graph (weights 1–5) to unweighted SSSP solvable by BFS |
| 2022–23 | Q2(a) | 8 | Algorithm for shortest path when all edge weights are equal |

### 4.2 DFS & Traversal Applications

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q5(c) | 10 | Linear-time algorithm to compute the reverse of a directed graph in adjacency list format |
| 2020–21 | Q2(c) | 13 | Jack Straws — find all connected pairs of straws using graph connectivity |

### 4.3 MST — Kruskal & Prim

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q1(a) | 3+5+7 | Define spanning tree; write Kruskal's; analyze complexity with efficient data structures |
| 2017–18 | Q1(b) | 10 | Find MST using Prim's on a given graph; show every step |
| 2017–18 | Q1(c) | 10 | Prove the cut property — minimum-weight crossing edge belongs to some MST |
| 2018–19 | Q1(b)-i | 8 | Prove an optimal MST is composed of optimal MST subtrees |
| 2018–19 | Q1(b)-ii | 7 | Draw an MST that must contain specific edges with weights x and z |
| 2020–21 | Q1(c) | 15 | Can MST of G_new (one new vertex added) be formed by adding one edge to existing MST? |
| 2021–22 | Q1(a) | 8 | Define and distinguish the two basic properties of greedy algorithms |
| 2021–22 | Q1(b) | 12 | Prove optimal sub-structure and greedy choice property for MST |
| 2021–22 | Q1(c) | 15 | Implement Kruskal's using disjoint set / union-find with array representation |
| 2019–20 | Q6(b) | 10 | For each MST T of G, show there exists an edge ordering that makes Kruskal's return T |

---

## 5. SSSP

### 5.1 Dijkstra's Algorithm

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q8(c) | 5+5+7+5 | Write, prove correctness, analyze complexity; running time with Fibonacci heap |
| 2018–19 | Q1(a) | 15 | Line-by-line complexity analysis with adjacency list + ordinary array |
| 2019–20 | Q6(a) | 15 | Modify Dijkstra's for maximum bandwidth path (bottleneck = min edge weight) |
| 2020–21 | Q1(b) | 12 | Solve minimum-sum descent in a triangle using Dijkstra's |

### 5.2 Bellman-Ford

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q8(b) | 6+2 | Intuition behind Bellman-Ford; detect negative cycles |
| 2019–20 | Q6(c) | 10 | Express SSSP as matrix-vector product; relate to Bellman-Ford |
| 2022–23 | Q2(c) | 15 | Efficient algorithm for SSSP with negative weights and negative cycles |

### 5.3 Miscellaneous

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q7(b) | 10 | Find the minimum-length (edge count) negative-weight cycle in a graph |
| 2019–20 | Q5(b) | 12 | Prove minimum-weight connected edge subset is a tree iff all weights positive; show counterexample |
| 2020–21 | Q2(a) | 12 | Single-destination shortest paths with nonnegative vertex weights in addition to edge weights |
| 2022–23 | Q2(b) | 12 | SSSP algorithm for non-equal but positive edge weights |

---

## 6. APSP

### 6.1 Johnson's Algorithm

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q2(a) | 15 | Explain the core idea of Johnson's algorithm (reweighting via Bellman-Ford + Dijkstra's) |
| 2022–23 | Q1(a) | 12 | Analyze the time complexity of Johnson's algorithm |

### 6.2 Floyd-Warshall / Warshall

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2020–21 | Q2(b) | 10 | Implement Warshall's algorithm in-place without extra memory for intermediate matrices |

### 6.3 Variants

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q2(d) | 9 | All-pairs strongest path — strength = min edge weight on path; design algorithm |
| 2019–20 | Q7(c) | 12 | All-pairs shortest paths in a strongly connected graph, constrained to pass through v₀ |

---

*Last updated: April 2026 · BUET CSE 207 · L-2/T-2*
