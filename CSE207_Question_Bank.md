# CSE 207 — Data Structures & Algorithms II
## Question Bank (2017–18 to 2022–23)

> **Source:** BUET L-2/T-2 Term Final Examinations  
> **Topics covered:** Flow / Max-flow · Red-Black Tree · AVL Tree · BFS & DFS · SSSP · APSP

---

## Table of Contents

1. [Flow / Max-flow](#1-flow--max-flow)
   - [Ford-Fulkerson & Edmonds-Karp](#11-ford-fulkerson--edmonds-karp)
   - [Min-cut Theorem](#12-min-cut-theorem)
   - [Bipartite Matching](#13-bipartite-matching)
   - [Application Problems](#14-application-problems)
2. [Red-Black Tree (RBT)](#2-red-black-tree-rbt)
   - [Properties & Proofs](#21-properties--proofs)
   - [Insertion](#22-insertion)
   - [Deletion](#23-deletion)
   - [Conceptual Questions](#24-conceptual-questions)
3. [AVL Tree](#3-avl-tree)
   - [Properties & Proofs](#31-properties--proofs)
   - [Rotations & Balancing](#32-rotations--balancing)
   - [Insertion](#33-insertion)
   - [Fibonacci / Node Count](#34-fibonacci--node-count)
4. [BFS, DFS & MST](#4-bfs-dfs--mst)
   - [BFS for Shortest Paths](#41-bfs-for-shortest-paths)
   - [DFS & Graph Traversal Applications](#42-dfs--graph-traversal-applications)
   - [MST — Kruskal & Prim](#43-mst--kruskal--prim)
5. [SSSP — Single Source Shortest Paths](#5-sssp--single-source-shortest-paths)
   - [Dijkstra's Algorithm](#51-dijkstras-algorithm)
   - [Bellman-Ford Algorithm](#52-bellman-ford-algorithm)
   - [Negative Cycles & Miscellaneous](#53-negative-cycles--miscellaneous)
6. [APSP — All Pairs Shortest Paths](#6-apsp--all-pairs-shortest-paths)
   - [Johnson's Algorithm](#61-johnsons-algorithm)
   - [Floyd-Warshall / Warshall](#62-floyd-warshall--warshall)
   - [All-Pairs Variants](#63-all-pairs-variants)

---

## 1. Flow / Max-flow

### 1.1 Ford-Fulkerson & Edmonds-Karp

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q2(b) | 10 | Find the maximum flow and the minimum cut in the given flow network using **Ford-Fulkerson** algorithm. Vertex *s* is the source, vertex *t* is the sink. |
| 2017–18 | Q2(c) | 10 | Describe the **minimum path length augmentation** method of Edmonds and Karp. Explain how this method improves the time complexity of Ford-Fulkerson. |
| 2018–19 | Q2(b) | 15 | For the given flow network, find the value of the maximum flow by **drawing residual networks** in each step. Draw the maximum flow network and identify the min-cut. |
| 2022–23 | Q3(c) | 5 | What is the **Edmonds-Karp optimization** for the Ford-Fulkerson algorithm? |

### 1.2 Min-cut Theorem

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2019–20 | Q3(b) | 8 | **Prove the max-flow min-cut theorem.** |

### 1.3 Bipartite Matching

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2022–23 | Q3(b) | 6+6 | **Formulate the maximum bipartite matching problem.** Give two examples of real-life problems solvable using it. |
| 2022–23 | Q3(c) | 10 | **Develop a solution** for the maximum bipartite matching problem. |

### 1.4 Application Problems

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2019–20 | Q8(b) | 23 | **Ad-hoc network backup sets:** Each device x must have k backup devices within distance D, with no device appearing in more than b backup sets. (i) Reduce to a max-flow problem. (ii) Prove correctness. (iii) Give an algorithm and state its running time as a function of n, k, b. |
| 2020–21 | Q3(a) | 10 | You want to **increase max-flow by increasing capacity of exactly one edge**. How do you find the best edge? Give pseudocode. State the running time. |
| 2020–21 | Q4(a) | 15 | The **edge connectivity** of an undirected graph is the minimum number of edges to remove to disconnect it. Show how to determine edge connectivity of G=(V,E) by running a max-flow algorithm on at most |V| flow networks, each with O(V) vertices and O(E) edges. |
| 2021–22 | Q4(a) | 8 | **Define the Max-flow problem.** |
| 2021–22 | Q4(b) | 12+15 | **Car parking matching problem:** Cars and parking spots are in different parts of a city, accessible through a road network graph G. Cost from car *a* to spot *b* is the shortest path in G (∞ if unreachable). (i) Formulate using Max-flow/min-cut. (ii) Develop an efficient solution minimizing overall cost. |
| 2022–23 | Q1(b) | 23 | **Peculiar city problem:** A city has N towns and M bidirectional roads of three types. Men can use types 1 & 3; women can use types 2 & 3. Maximize the number of roads under renovation while the city remains connected for both. (i) Formulate as a graph problem. (ii) Develop solution using a known algorithm. (iii) Write pseudocode. |

---

## 2. Red-Black Tree (RBT)

### 2.1 Properties & Proofs

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q5(a) | 12 | **Prove that a tree with n nodes** where the heights of the two children of any node differ by at most 1 has O(log n) height. |
| 2021–22 | Q2(c) | 15 | What are the **properties of a red-black tree**? Derive that if a tree with n keys follows the red-black properties, its height h can be bounded as h ≤ 2lg(n+1). |

### 2.2 Insertion

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q5(b) | 15 | **Insert 11** into the given Red-Black tree. Show each operation. (Red = R, Black = B.) |
| 2019–20 | Q4(c) | 15 | **Insert 11** into the given Red-Black tree. Show all intermediate steps. |
| 2022–23 | Q4(c) | 15 | Write **pseudocode for RB-tree insertion**. Explain (graphically) the different forms of transformation needed to maintain RB properties during insertion. Briefly compare RB-tree and AVL-tree. |

### 2.3 Deletion

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2020–21 | Q6(b) | 5+15 | Usually we fix an RB-tree after deleting a node when properties get violated. **Explain whether it is possible to fix without any rotation.** Then, delete the node with key = 150 from the given RB-tree, showing all steps and the resulting tree. |

### 2.4 Conceptual Questions

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2018–19 | Q4(a)-i | 5 | When inserting into an RB-tree, **why is the new node colored red** and not black? |
| 2018–19 | Q4(a)-ii | 5 | Would **inserting then immediately deleting** a node change the RB-tree? Explain with an example. |
| 2018–19 | Q4(a)-iii | 5 | What is the **ratio between the longest and shortest path** in a red-black tree? |
| 2020–21 | Q7(d) | 5 | Mr. X proposes inserting nodes as **black by default**. Discuss advantages and disadvantages over traditional RB-tree insertion. |
| 2017–18 | Q5(c) | 4 | Mention **one advantage of AVL trees over RB-trees**, and one advantage of RB-trees over AVL trees. |

---

## 3. AVL Tree

### 3.1 Properties & Proofs

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q5(a) | 12 | **Prove that a height-balanced tree with n nodes has O(log n) height.** (Heights of any node's two children differ by at most 1.) |
| 2021–22 | Q2(c) | 15 | *(Same as RBT 2.1 above — also covers AVL)* What are the properties of a red-black tree? Derive height bound h ≤ 2lg(n+1). |
| 2022–23 | Q4(b) | 12 | **Write down the properties of an AVL-tree** and prove that it is a balanced binary search tree. |
| 2019–20 | Q4(b) | 12 | **Prove or disprove:** (i) In an AVL tree, the difference in length between the shortest and longest root-to-leaf paths is at most one. (ii) The minimum number of nodes in an AVL tree with height 5 is 20. |

### 3.2 Rotations & Balancing

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2018–19 | Q3(a) | 15 | (i) **What rotations are required to balance an AVL tree?** (ii) How does a rotation balance an AVL tree? (iii) What is the maximum height of an AVL tree having 10 nodes? |
| 2021–22 | Q2(b) | 12 | Inserting a node into an AVL tree where x is the **lowest node violating AVL** and x is left-heavy — **demonstrate the balancing procedure** using figures. |

### 3.3 Insertion

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2020–21 | Q7(a) | 5+5 | **Insert key = 20** into the given AVL tree, then **insert key = 68** into the resulting tree. Show all steps and resulting AVL trees. |

### 3.4 Fibonacci / Node Count

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q5(d) | 4 | If the i-th and (i+2)-th Fibonacci numbers are x and y respectively (i > 0), what is the **minimum number of nodes in an AVL tree with height (i−1)**? |

---

## 4. BFS, DFS & MST

### 4.1 BFS for Shortest Paths

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q8(a) | 5 | How can **BFS be adapted** to solve SSSP in an edge-weighted graph with unequal weights? Explain. |
| 2019–20 | Q5(a) | 13 | Given a graph with **integer edge weights between 1 and 5**, how would you reduce this to the shortest unweighted path problem solvable by BFS? |
| 2022–23 | Q2(a) | 8 | **Develop an algorithm** for finding the shortest path in a graph where all edge weights are equal. |

### 4.2 DFS & Graph Traversal Applications

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2019–20 | Q5(c) | 10 | The **reverse of a directed graph** G=(V,E) is G_R=(V,E_R) where E_R = {(v,u) : (u,v) ∈ E}. Give a **linear-time algorithm** for computing the reverse in adjacency list format. |
| 2020–21 | Q2(c) | 13 | **Jack Straws problem:** Given endpoints of n > 1 straws dumped on a large piece of graph paper, determine all pairs of straws that are connected (directly or indirectly via touching straws). |
| 2020–21 | Q3(b) | 10 | **Gale-Shapley / Stable matching:** Consider a woman w who prefers man m to m', but both are low on her preference list. Can she benefit by falsely swapping them? Give proof. |

### 4.3 MST — Kruskal & Prim

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q1(a) | 3+5+7 | What is a **spanning tree**? Write **Kruskal's algorithm** for MST. Analyze time complexity with efficient data structures. |
| 2017–18 | Q1(b) | 10 | Find an **MST using Prim's algorithm** on the given graph, showing every step. |
| 2017–18 | Q1(c) | 10 | Let G be weighted and connected. Let V₁, V₂ partition the vertices. Let e be the **minimum-weight crossing edge**. **Prove** there is an MST containing e. |
| 2018–19 | Q1(b)-i | 8 | **Prove that an optimal MST is composed of optimal MST subtrees.** |
| 2018–19 | Q1(b)-ii | 7 | Draw an MST of the given graph G such that the MST **contains edges with weights x and z**. |
| 2020–21 | Q1(c) | 15 | Let T be an MST of G obtained by Prim's. G_new is formed by adding a new vertex and edges to G. **Can you construct an MST of G_new by adding one new edge to T?** If yes, how; if no, why not. |
| 2021–22 | Q1(a) | 8 | **Define and distinguish the two basic properties** of the greedy algorithm. |
| 2021–22 | Q1(b) | 12 | **Prove the optimal sub-structure property and the greedy choice property** of the MST problem. |
| 2021–22 | Q1(c) | 15 | **Develop a solution for MST** using disjoint set / union-find data structure. Use the array implementation to maintain union-find. |
| 2019–20 | Q6(b) | 10 | Kruskal's can return different spanning trees for the same graph. Show that **for each MST T of G, there is a way to sort G's edges** so that Kruskal's returns T. |

---

## 5. SSSP — Single Source Shortest Paths

### 5.1 Dijkstra's Algorithm

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q8(c) | 5+5+7+5 | Write **Dijkstra's algorithm**. Prove its correctness. Analyze time complexity. What is the running time with a **Fibonacci heap** instead of a binary heap? |
| 2018–19 | Q1(a) | 15 | **Line-by-line complexity analysis of Dijkstra's algorithm** when adjacency list is used for graph representation and an ordinary array for storing d[] values. |
| 2019–20 | Q6(a) | 15 | **FastRoute — maximum bandwidth path:** Modify Dijkstra's to find the path with maximum bandwidth (bandwidth = minimum edge weight along the path). Justify your answer. |
| 2020–21 | Q1(b) | 12 | **Minimum-sum descent:** Positive integers arranged in an equilateral triangle. Find the smallest sum in a descent from the apex to the base. Explain how this can be solved by Dijkstra's algorithm. |
| 2019–20 | Q7(c) | 12 | Strongly connected directed graph G=(V,E) with positive edge weights and a particular node v₀ ∈ V. Give an efficient algorithm for finding **shortest paths between all pairs, restricted to passing through v₀**. |

### 5.2 Bellman-Ford Algorithm

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q8(b) | 6+2 | **Explain the intuitive idea behind Bellman-Ford.** How do you detect a **negative cycle** using Bellman-Ford? |
| 2019–20 | Q6(c) | 10 | Show how to express the SSSP problem as a **product of matrices and a vector**. Describe how evaluating this product corresponds to a **Bellman-Ford-like algorithm**. |
| 2022–23 | Q2(c) | 15 | Develop an efficient algorithm for the shortest path problem when **edge weights can be negative** and the graph can have **negative edge-weight cycles**. |

### 5.3 Negative Cycles & Miscellaneous

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2019–20 | Q7(b) | 10 | Give an efficient algorithm to find the **length (number of edges) of a minimum-length negative-weight cycle** in a graph. |
| 2019–20 | Q5(b) | 12 | **Prove:** If all edge weights are positive, any minimum-weight subset of edges connecting all vertices must be a tree. Give an example showing this **fails if weights can be nonpositive**. |
| 2020–21 | Q2(a) | 12 | **Single-destination shortest-paths problem:** Solve in a graph with nonnegative numbers assigned to vertices *in addition* to edge weights. |
| 2022–23 | Q2(b) | 12 | Devise an efficient algorithm for SSSP where **edge weights are non-equal but positive**. |

---

## 6. APSP — All Pairs Shortest Paths

### 6.1 Johnson's Algorithm

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2018–19 | Q2(a) | 15 | Johnson's Algorithm uses both Bellman-Ford and Dijkstra's for APSP on sparse graphs. **Explain the basic clever idea** of Johnson's Algorithm. |
| 2022–23 | Q1(a) | 12 | **Analyze the complexity of Johnson's algorithm** for the all-pairs shortest paths problem. |

### 6.2 Floyd-Warshall / Warshall

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2020–21 | Q2(b) | 10 | Explain how to implement **Warshall's algorithm without using extra memory** for storing elements of the algorithm's intermediate matrices. |

### 6.3 All-Pairs Variants

| Year | Q | Marks | Question |
|------|---|-------|----------|
| 2017–18 | Q2(d) | 9 | The **strength of a path** = minimum edge weight along it. The **all-pairs strongest path problem** asks for the strongest path between every pair of vertices. Design an algorithm to solve it. |
| 2019–20 | Q7(c) | 12 | Given a strongly connected directed graph G=(V,E) with positive weights and node v₀ ∈ V, find shortest paths between **all pairs that must pass through v₀**. |

---

*Last updated: April 2026 · BUET CSE 207 · L-2/T-2*
