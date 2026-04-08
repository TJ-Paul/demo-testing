# CSE 207 — Data Structures & Algorithms II
## Full Question Bank (2017–18 to 2022–23)

> **Source:** BUET L-2/T-2 Term Final Examinations  
> **Years covered:** 2017–18 · 2018–19 · 2019–20 · 2020–21 · 2021–22 · 2022–23

---

## Table of Contents

1. [Graph Algorithms — MST](#1-graph-algorithms--mst)
2. [Graph Algorithms — SSSP](#2-graph-algorithms--sssp)
3. [Graph Algorithms — APSP](#3-graph-algorithms--apsp)
4. [Network Flow & Matching](#4-network-flow--matching)
5. [Red-Black Tree](#5-red-black-tree)
6. [AVL Tree](#6-avl-tree)
7. [Splay Tree](#7-splay-tree)
8. [Skip List](#8-skip-list)
9. [Hashing](#9-hashing)
10. [Binomial Heap](#10-binomial-heap)
11. [Fibonacci Heap](#11-fibonacci-heap)
12. [NP-Completeness & Complexity](#12-np-completeness--complexity)
13. [Approximation Algorithms](#13-approximation-algorithms)
14. [Backtracking & Branch and Bound](#14-backtracking--branch-and-bound)
15. [Dynamic Programming](#15-dynamic-programming)
16. [Randomized Algorithms](#16-randomized-algorithms)
17. [Miscellaneous / Problem Solving](#17-miscellaneous--problem-solving)

---

## 1. Graph Algorithms — MST

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q1(a) | 3+5+7 | Define spanning tree; write Kruskal's algorithm; analyze time complexity with efficient data structures |
| 2017–18 | Q1(b) | 10 | Find MST of a given graph using Prim's algorithm; show every step |
| 2017–18 | Q1(c) | 10 | Prove the cut property — minimum-weight crossing edge belongs to some MST |
| 2018–19 | Q1(b)-i | 8 | Prove an optimal MST is composed of optimal MST subtrees |
| 2018–19 | Q1(b)-ii | 7 | Draw an MST of a given graph that must contain edges with specific weights x and z |
| 2019–20 | Q5(b) | 12 | Prove that minimum-weight connected edge subset must be a tree when all weights are positive; give counterexample for nonpositive weights |
| 2019–20 | Q6(b) | 10 | For every MST T of G, show there is an edge ordering that makes Kruskal's return T |
| 2020–21 | Q1(c) | 15 | Adding a new vertex to G forms G_new — can MST of G_new be built by adding one edge to existing MST T? |
| 2021–22 | Q1(a) | 8 | Define and distinguish the two basic properties of the greedy algorithm |
| 2021–22 | Q1(b) | 12 | Prove optimal sub-structure and greedy choice property for MST |
| 2021–22 | Q1(c) | 15 | Implement Kruskal's using disjoint set / union-find with array implementation |

---

## 2. Graph Algorithms — SSSP

### Dijkstra's Algorithm

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q8(a) | 5 | Adapt BFS for SSSP on graphs with unequal edge weights |
| 2017–18 | Q8(c) | 5+5+7+5 | Write Dijkstra's; prove correctness; analyze complexity; running time with Fibonacci heap |
| 2018–19 | Q1(a) | 15 | Line-by-line time complexity analysis of Dijkstra's with adjacency list and ordinary array |
| 2019–20 | Q5(a) | 13 | Reduce a weighted graph (integer weights 1–5) to an unweighted SSSP problem solvable by BFS |
| 2019–20 | Q6(a) | 15 | Modify Dijkstra's to find maximum-bandwidth path (bandwidth = min edge weight on path) |
| 2020–21 | Q1(a) | 8 | Design an efficient algorithm for the longest path in a DAG |
| 2020–21 | Q1(b) | 12 | Solve minimum-sum descent in an equilateral number triangle using Dijkstra's algorithm |
| 2022–23 | Q2(a) | 8 | Algorithm for shortest path when all edge weights are equal |
| 2022–23 | Q2(b) | 12 | Efficient SSSP algorithm when edge weights are non-equal but positive |

### Bellman-Ford Algorithm

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q8(b) | 6+2 | Intuition behind Bellman-Ford; detect negative cycles |
| 2019–20 | Q6(c) | 10 | Express SSSP as a matrix-vector product; relate evaluation to Bellman-Ford |
| 2019–20 | Q7(b) | 10 | Find minimum-length (fewest edges) negative-weight cycle in a graph |
| 2020–21 | Q2(a) | 12 | Single-destination shortest paths in a graph with nonnegative vertex weights added to edge weights |
| 2022–23 | Q2(c) | 15 | SSSP algorithm when edge weights can be negative and graph may have negative cycles |

### Miscellaneous SSSP

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q5(c) | 10 | Linear-time algorithm to compute the reverse of a directed graph in adjacency list format |
| 2019–20 | Q7(c) | 12 | All-pairs shortest paths in a strongly connected graph restricted to paths through a fixed vertex v₀ |
| 2020–21 | Q2(b) | 10 | Implement Warshall's algorithm in-place without extra memory for intermediate matrices |

---

## 3. Graph Algorithms — APSP

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q2(d) | 9 | All-pairs strongest path — strength = min edge weight on path; design an algorithm |
| 2018–19 | Q2(a) | 15 | Explain the core reweighting idea of Johnson's algorithm (Bellman-Ford + Dijkstra's) |
| 2018–19 | Q1(a) | 15 | *(See SSSP — also covers Dijkstra's complexity used inside Johnson's)* |
| 2020–21 | Q2(b) | 10 | Warshall's algorithm in-place — no extra memory for intermediate matrices |
| 2022–23 | Q1(a) | 12 | Analyze time complexity of Johnson's algorithm for all-pairs shortest paths |

---

## 4. Network Flow & Matching

### Ford-Fulkerson & Edmonds-Karp

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q2(a) | 3+3 | Define a flow network; define an augmenting path with examples |
| 2017–18 | Q2(b) | 10 | Apply Ford-Fulkerson on a given network; find max-flow and min-cut |
| 2017–18 | Q2(c) | 10 | Describe Edmonds-Karp (min path length augmentation); explain time complexity improvement |
| 2018–19 | Q2(b) | 15 | Find max-flow by drawing residual networks step by step; identify min-cut |
| 2022–23 | Q3(c) | 5 | State the Edmonds-Karp optimization for Ford-Fulkerson |

### Max-flow Min-cut Theorem

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q3(b) | 8 | Prove the max-flow min-cut theorem |

### Bipartite Matching

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q3(b) | 6+6 | Formulate max bipartite matching; give two real-life examples |
| 2022–23 | Q3(c) | 10 | Develop a solution for max bipartite matching |

### Application Problems

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q8(b) | 10+7+6 | Ad-hoc wireless backup sets — reduce to max-flow, prove correctness, give running time |
| 2020–21 | Q3(a) | 10 | Find the single edge whose capacity increase maximally boosts total network flow |
| 2020–21 | Q3(b) | 10 | Gale-Shapley stable matching — can a woman benefit by falsely reordering her preference list? Prove your answer |
| 2020–21 | Q4(a) | 15 | Determine edge connectivity of undirected G=(V,E) by running max-flow on at most \|V\| networks |
| 2020–21 | Q4(b) | 7 | Define fixed-parameter tractability; explain why it is useful |
| 2021–22 | Q4(a) | 8 | Define the max-flow problem |
| 2021–22 | Q4(b)-i | 12 | Car-parking assignment — formulate as max-flow / min-cut problem |
| 2021–22 | Q4(b)-ii | 15 | Car-parking assignment — develop efficient solution to minimize overall travel cost |
| 2022–23 | Q1(b) | 23 | Peculiar city with gender-restricted road types — maximize roads under renovation while keeping connectivity; formulate, develop solution, write pseudocode |

---

## 5. Red-Black Tree

### Properties & Proofs

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(a) | 12 | Prove a height-balanced tree (children heights differ by ≤1) with n nodes has O(log n) height |
| 2021–22 | Q2(c) | 15 | State RBT properties; derive height bound h ≤ 2lg(n+1) |

### Insertion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(b) | 15 | Insert 11 into a given RBT; show all fixup steps |
| 2019–20 | Q4(c) | 15 | Insert 11 into a given RBT; show all intermediate steps |
| 2022–23 | Q4(c) | 15 | Write RBT insertion pseudocode; show all rotation/recoloring cases graphically; compare RBT vs AVL |

### Deletion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2020–21 | Q6(b) | 5+15 | Can RBT be fixed after deletion without any rotation? Delete key=150 from a given tree; show all steps |

### Conceptual

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(c) | 4 | One advantage of AVL over RBT, and one advantage of RBT over AVL |
| 2018–19 | Q4(a)-i | 5 | Why is a newly inserted RBT node colored red and not black? |
| 2018–19 | Q4(a)-ii | 5 | Does inserting then immediately deleting a node change the RBT? Explain with example |
| 2018–19 | Q4(a)-iii | 5 | What is the ratio of the longest path to the shortest path in an RBT? |
| 2020–21 | Q7(d) | 5 | Pros and cons of inserting new nodes as black by default (Mr. X's variant) |

---

## 6. AVL Tree

### Properties & Proofs

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(a) | 12 | Prove height-balanced tree with n nodes has O(log n) height |
| 2019–20 | Q4(b)-i | 6 | Prove or disprove: difference between shortest and longest root-to-leaf path is at most one |
| 2019–20 | Q4(b)-ii | 6 | Prove or disprove: minimum number of nodes in an AVL tree of height 5 is 20 |
| 2022–23 | Q4(b) | 12 | State AVL tree properties; prove it is a balanced BST |

### Rotations & Balancing

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q3(a)-i | 5 | What rotations are required to balance an AVL tree? |
| 2018–19 | Q3(a)-ii | 5 | How does a rotation restore balance in an AVL tree? |
| 2018–19 | Q3(a)-iii | 5 | What is the maximum height of an AVL tree with 10 nodes? |
| 2021–22 | Q2(b) | 12 | Demonstrate AVL balancing when the lowest violating node x is left-heavy |

### Insertion

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2020–21 | Q7(a) | 5+5 | Insert key=20, then key=68 into a given AVL tree; show all steps and resulting trees |

### Fibonacci / Node Count

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q5(d) | 4 | Given i-th and (i+2)-th Fibonacci numbers x and y, find minimum nodes in AVL tree of height (i−1) |

---

## 7. Splay Tree

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q6(a) | 10 | Perform splay(1) on a given BST; show intermediate steps and name operations at each node |
| 2017–18 | Q6(d) | 5 | What is the main objective of splay trees? Do splay trees explicitly try to balance height? |
| 2018–19 | Q3(b)-i | 8 | Access keys 3 then 9 in a given splay tree; show the resulting tree |
| 2018–19 | Q3(b)-ii | 7 | Delete key 6 from the splay tree obtained after part (i); show the result |
| 2020–21 | Q6(a) | 5+10 | Define the rank of a splay tree node; prove that potential change from a non-splay insertion is O(log n) |
| 2022–23 | Q3(a) | 8 | Explain how the potential function concept is used in the design of a splay tree |

---

## 8. Skip List

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q4(b)-i | 8 | Prove expected space usage of a skip list with n entries is O(n) |
| 2018–19 | Q4(b)-ii | 7 | Prove expected search and insertion time in a skip list is O(log n) |
| 2020–21 | Q5(b) | 5+10 | Prove expected space of skip list is O(n); perform insert(17, i=2), insert(25, i=4), delete(25) on a given skip list |
| 2020–21 | Q5(a) | 10 | A friend claims Find-Min in a binomial heap can be done in O(1) using Fibonacci heap idea; justify or refute |

---

## 9. Hashing

### Separate Chaining

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q5(a) | 12 | Prove unsuccessful search under simple uniform hashing with separate chaining takes expected O(1+α) |
| 2019–20 | Q1(a) | 10 | Prove successful search under simple uniform hashing with separate chaining requires expected O(1+α) |
| 2019–20 | Q1(b) | 10 | N dinner guests arriving at a hash table — achieve 1+log α expected time for unsuccessful search |
| 2021–22 | Q6(b) | 10 | Analyze running time of chaining hashtable for both successful and unsuccessful search |
| 2017–18 | Q7(c) | 10 | Under simple uniform hashing with separate chaining (m chains, n items), find expected number of collisions with element x |

### Open Addressing & Probing

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q7(d)-i | 5 | Prove or disprove: quadratic probing does not necessarily probe all locations in a hash table |
| 2018–19 | Q5(b) | 6 | Agree or disagree: quadratic probing does not necessarily probe all locations; justify |
| 2018–19 | Q5(c) | 12 | Insert keys 14,3,29,3,19,16,35,2 into hash table of size 11 using h(k)=k mod m and quadratic probing |
| 2019–20 | Q1(c) | 15 | Insert keys into hash table of size 11 using (i) linear probing and (ii) quadratic probing |
| 2020–21 | Q7(c) | 10 | Choose between separate chaining and open addressing for a new language's hash table; justify choice |

### Double Hashing & Comparison

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q6(a)-i | 15 | Compare quadratic probing (size 16) vs double hashing (size 17) by counting total unsuccessful probes during insertion |
| 2022–23 | Q6(a)-ii | 5 | Identify why key 150 is not found after deleting key 100 in the quadratic probing implementation; provide fix |
| 2021–22 | Q6(a)-i | 15 | Compare quadratic probing (size 15) vs double hashing (size 17) — count total unsuccessful probes during insertion |
| 2021–22 | Q6(a)-ii | 5 | Comment on friend's suggestion about hash table size |
| 2021–22 | Q6(a)-iii | 5 | Identify why key 700 is not found after deleting key 110; provide fix |

### Perfect Hashing

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q7(d)-ii | 5 | Briefly discuss the concept of perfect hashing |

---

## 10. Binomial Heap

### Properties & Proofs

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q7(a) | 4+6 | Define "maximally damaged tree" in Fibonacci heaps; draw the maximally damaged tree of order 5 |
| 2017–18 | Q7(b) | 5 | Prove there are ᵏCᵢ nodes at depth i in binomial tree Bₖ |
| 2018–19 | Q6(a) | 10 | Prove there are ᵏCᵢ nodes at depth i in binomial heap Bₖ of order k |
| 2019–20 | Q2(a) | 10 | Prove there are ᵏCᵢ nodes at depth i in binomial heap Bₖ of order k |
| 2022–23 | Q8(b) | 12 | Prove amortized cost of INSERT is O(1) and worst-case cost of EXTRACT-MIN and DECREASE-KEY is O(log n) |

### Operations & Complexity

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q6(b) | 6+6 | State running times of Insert, Find-min, Extract-min, Union, Decrease-key for both binomial and Fibonacci heaps; evaluate friend's O(1)-all-ops claim |
| 2018–19 | Q6(c) | 5 | State running times of Union, Find-min, Extract-min, Decrease-key for binomial and Fibonacci heaps |
| 2019–20 | Q4(a) | 8 | State amortized running times of Union, Find-min, Extract-min, Decrease-key for binomial and Fibonacci heaps |
| 2020–21 | Q5(a) | 10 | Claim: Find-Min in binomial heap can be O(1) using Fibonacci heap idea — justify |

### Insertion & Deletion on Given Heap

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2019–20 | Q2(b) | 17 | Delete node X with key=17 from a given binomial heap; show intermediate steps |
| 2022–23 | Q8(a)-i | 8 | Insert given sequence into two initially empty binomial heaps pq1 and pq2; draw resulting heaps |
| 2022–23 | Q8(a)-ii | 10 | Meld pq1 and pq2; decrease key of node 20 to −20; show all steps |
| 2022–23 | Q8(a)-iii | 5 | Compute total actual credits for two consecutive Extract-Max operations on the melded heap |
| 2021–22 | Q5(a) | 15 | Convert min priority queue to max priority queue in O(n) amortized; analyze using potential method |
| 2021–22 | Q5(b) | 5 | Apply the conversion algorithm to a given min binomial heap pq2 |
| 2021–22 | Q5(c) | 5 | Meld pq1 and converted pq2 into pq3; show internal heap representation |
| 2021–22 | Q5(d) | 5 | Show internal heap representation after three Extract-Max operations on pq3 |
| 2021–22 | Q5(e) | 5 | Compute total actual credits for the three Extract-Max operations in part (d) |
| 2022–23 | Q8(b) | 12 | Prove amortized INSERT is O(1) and worst-case EXTRACT-MIN and DECREASE-KEY are O(log n) in binomial heap |

### Binomial Tree Structural Questions

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q8(d) | 5 | A binomial heap has 19 nodes — identify which binomial trees it contains |

---

## 11. Fibonacci Heap

### Properties & Structure

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q7(a) | 4+6 | Define "maximally damaged tree"; draw the maximally damaged tree of order 5 |
| 2019–20 | Q2(c) | 8 | Draw the maximally damaged tree of degree 6 (i.e., f₆) in the context of Fibonacci heaps |
| 2020–21 | Q5(c) | 5 | Describe how Fibonacci numbers are related to Fibonacci heaps |

### Operations on Given Heap

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q6(c) | 8 | Write the algorithm for extracting the minimum key from a Fibonacci heap |
| 2018–19 | Q6(b) | 15 | Delete the minimum node (key=3) from a given Fibonacci heap; show all intermediate steps |
| 2020–21 | Q8(a) | 5+10 | Prove/disprove: root nodes are never marked in decrease-key; perform Extract-Min on a given Fibonacci min-heap |

### Amortized Analysis & Potential

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q5(c)-i | 6 | Construct an upper bound on actual time of RAHSUT-DELETE (variant delete) in terms of x.degree and cascading-cut calls c |
| 2022–23 | Q5(c)-ii | 6 | Find the potential of the resulting heap H' after RAHSUT-DELETE in terms of x.degree, c, t(H), and m(H) |

---

## 12. NP-Completeness & Complexity

### P, NP, NP-hard, NP-complete Definitions

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q4(a) | 3+7 | Define X ≤ₚ Y; show vertex cover ≤ₚ set cover |
| 2018–19 | Q7(a) | 12 | Prove P = NP ⟹ NP = co-NP |
| 2018–19 | Q7(b) | 6 | Prove or disprove: TAUTOLOGY is in co-NP |
| 2019–20 | Q3(a) | 8 | Suppose X ∈ NP-complete; prove X ∈ P if and only if P = NP |
| 2020–21 | Q7(b) | 7+3 | Using an example show if a problem is in NP its complement is in co-NP; draw Venn diagram for P, NP, co-NP |
| 2022–23 | Q5(a) | 6 | Differentiate among NP, NP-hard, and NP-complete classes |
| 2020–21 | Q8(c) | 5 | Explain how to prove an optimization problem is NP-complete |

### Reductions

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q4(b) | 3+7 | Define satisfiability; show Independent Set is NP-hard by reducing 3-SAT to it |
| 2018–19 | Q7(c) | 12 | Prove vertex cover is at least as hard as independent set (reduction) |
| 2019–20 | Q3(b) | 12 | Prove set cover is at least as hard as vertex cover |
| 2021–22 | Q7(a)-i | 5 | Map the social media minimal influencer problem to a known NP-complete problem |
| 2021–22 | Q7(a)-ii | 10 | Prove the social media influencer problem is NP-complete using 3-SAT reduction |
| 2022–23 | Q5(b) | 17 | Map the team task-scheduling problem to an NP-complete problem; reduce to another NP-complete problem to show NP-hardness |

### Set Cover & Packing

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q4(c) | 3+7 | Give approximation algorithm for set cover; compute approximation ratio |
| 2017–18 | Q4(d) | 5 | If a polynomial-time algorithm for set-packing is found, what are the implications? |

---

## 13. Approximation Algorithms

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q3(d) | 2+3+5 | Discuss approximability of general TSP; give approximation algorithm for Euclidean TSP; compute ratio |
| 2017–18 | Q4(c) | 3+7 | Give approximation algorithm for set cover; compute approximation ratio |
| 2018–19 | Q8(a) | 10 | Give 2-approximation algorithm for vertex cover; prove it computes a cover at most twice the optimal |
| 2018–19 | Q8(a) | 10 | *(Same as above — vertex cover 2-approximation)* |
| 2019–20 | Q8(a) | 12 | TSP near-optimal solution using minimum spanning tree (satisfies triangle inequality); construct and show on given graph |
| 2020–21 | Q4(c) | 13 | Bottleneck TSP — design polynomial-time 3-approximation algorithm (triangle inequality assumed) |
| 2020–21 | Q2(c) | 13 | Rumor spreading — design greedy algorithm minimizing messages needed for everyone to know all rumors |
| 2021–22 | Q6(a) | 15+5+5 | Hashtable comparison problem — see Hashing section |
| 2021–22 | Q8(b) | 15 | Apply FPTAS approximation algorithm (ε=0.1) to solve a given knapsack instance |
| 2021–22 | Q8(a) | 5 | Why does the FPTAS use OPT(i,v) subproblem instead of OPT(i,w)? |
| 2021–22 | Q8(c) | 15 | Prove the FPTAS computes a solution within (1+ε) of optimum in O(n³/ε) |
| 2022–23 | Q6(b) | 15 | Give 2-approximation algorithm for vertex cover; prove it is at most twice the optimal size |

---

## 14. Backtracking & Branch and Bound

### 0-1 Knapsack

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q3(b) | 10 | Solve a 0-1 knapsack instance using branch-and-bound with a state-space tree |
| 2019–20 | Q3(c) | 15 | Solve a 0-1 knapsack instance (capacity=10) using branch-and-bound; show the tree |
| 2022–23 | Q7(b) | 15 | Solve a 0-1 knapsack instance (capacity=60 kg, 6 items) using branch-and-bound |

### TSP — Branch and Bound

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q7(a) | 20 | Solve a 4-city TSP using an exponential O(n²2ⁿ) dynamic programming algorithm; find optimal tour |
| 2021–22 | Q7(b) | 20 | Solve a 6-city TSP using branch-and-bound combined with pruning; find optimal tour |

### Hamiltonian Circuit

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q3(c) | 10 | Apply backtracking to find a Hamiltonian circuit in a given graph; show state-space tree |

### SAT / Boolean Satisfiability

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q8(c) | 10 | Use backtracking to decide satisfiability of a given Boolean formula; show backtracking tree |
| 2020–21 | Q8(b) | 10 | Use backtracking to decide satisfiability of a given Boolean formula; find all satisfying assignments |

---

## 15. Dynamic Programming

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2022–23 | Q7(a) | 20 | 4-city TSP — give O(n²2ⁿ) DP algorithm and find the optimal tour on the given cost matrix |

---

## 16. Randomized Algorithms

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2018–19 | Q8(b) | 10 | Analyze the running time of randomized quicksort |
| 2020–21 | Q3(b) | 10 | Gale-Shapley stable matching — prove whether a woman can manipulate the algorithm by falsely reordering preferences |
| 2020–21 | Q3(c) | 15 | Jack Straws connectivity problem — give algorithm for all connected pairs |

---

## 17. Miscellaneous / Problem Solving

| Year | Q | Marks | Topic |
|------|---|-------|-------|
| 2017–18 | Q3(a) | 5 | How do we cope with hard (intractable) problems? Discuss general strategies |
| 2019–20 | Q3(a) | 8 | If X is NP-complete, prove X ∈ P iff P = NP |
| 2019–20 | Q7(a) | 13 | Vertex cover of a tree — give linear-time algorithm to find the size of the smallest vertex cover |
| 2020–21 | Q4(b) | 7 | Define fixed-parameter tractability (FPT); explain why it is useful |
| 2020–21 | Q2(c) | 13 | Rumor spreading with n people — design greedy algorithm to minimize total messages sent |
| 2020–21 | Q5(d) | 5 | TSP lower bound via MST in branch-and-bound — will it always give the correct answer? Is there a better bound? |
| 2021–22 | Q3(a) | 8 | Define the input/output of the Dhaka traffic road-building program |
| 2021–22 | Q3(b) | 12 | Sketch pseudocode for the road-building solution (pick node pair (u,v) maximizing sum of shortest-path improvements) |
| 2021–22 | Q3(c) | 15 | Develop the most efficient underlying algorithm (all-pairs shortest paths) for the road-building problem |
| 2022–23 | Q5(c) | 12 | Analyze RAHSUT-DELETE — a modified Fibonacci heap delete operation (Professor Rahsut's variant) |

---

*Last updated: April 2026 · BUET CSE 207 · L-2/T-2*
