# CSE 205 — Digital Logic Design | Question Bank

> **BUET | L-2/T-1 | 2017–2023**
> Compiled for quick revision. Each entry shows: **Year · Q# · Part · Short Description**.
> Questions are grouped by topic for easier navigation.

---

## 📑 Table of Contents

- [Boolean Algebra & Simplification](#-boolean-algebra--simplification)
- [K-Map & Tabulation Method](#-k-map--tabulation-method)
- [Logic Gates & Universal Gates](#-logic-gates--universal-gates)
- [Combinational Circuits — Adders & Subtractors](#-combinational-circuits--adders--subtractors)
- [Combinational Circuits — Comparators & Multipliers](#-combinational-circuits--comparators--multipliers)
- [Multiplexers (MUX)](#-multiplexers-mux)
- [Decoders & Encoders](#-decoders--encoders)
- [PLA (Programmable Logic Array)](#-pla-programmable-logic-array)
- [Flip-Flops & Latches](#-flip-flops--latches)
- [Counters](#-counters)
- [Shift Registers](#-shift-registers)
- [Synchronous Sequential Circuits](#-synchronous-sequential-circuits)
- [Asynchronous Sequential Circuits — Fundamental Mode](#-asynchronous-sequential-circuits--fundamental-mode)
- [State Minimization](#-state-minimization)
- [Mealy & Moore Machines](#-mealy--moore-machines)
- [Vending Machine Design](#-vending-machine-design)
- [Parity Circuits](#-parity-circuits)
- [Miscellaneous / Definitions](#-miscellaneous--definitions)

---

## 🔵 Boolean Algebra & Simplification

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (d) | Simplify `BCD' + ABC' + ACD` to both POS and SOP form |
| 2018-19 | Q1 | (d) | Simplify `ACD' + CD + AB' + ABCD` to POS and SOP |
| 2019-20 | Q7 | (b) | Show that dual of XOR equals its complement |
| 2021-22 | Q2 | (a) | Simplify `(A+B)'(A'+B')'` to minimum literals |
| 2022-23 | Q3 | (b) | Simplify `F(A,B,C,D) = Σ(0,1,2,5,8,9,10)` to SOP and POS |
| 2022-23 | Q4 | (a) | Convert `F = xy + x'z` to product of maxterms using distributive law |
| 2022-23 | Q3 | (c) | Show that dual of XOR equals its complement |

---

## 🔵 K-Map & Tabulation Method

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (c) | K-Map minimize 4-var SOP with don't cares; find PIs and EPIs |
| 2018-19 | Q1 | (c) | K-Map minimize 4-var function with don't cares; find PIs and EPIs |
| 2020-21 | Q2 | (b) | K-Map minimize 5-var function `f(v,w,x,y,z)` with don't cares; find PIs, EPIs, Minimal Sums |
| 2021-22 | Q1 | (b) | Find prime implicants of 4-var function using tabulation (Quine-McCluskey) method |
| 2022-23 | Q4 | (c) | Find PIs and EPIs of 4-var function using tabulation method |
| 2019-20 | Q6 | (b) | Convert SOP to simplified POS using K-Map for `F(w,x,y,z)` |
| 2019-20 | Q7 | (a) | Simplify `F(A,B,C,D)` using tabulation; find essential prime implicants |

---

## 🔵 Logic Gates & Universal Gates

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (b) | Express `f(A,B,C,D)` in NOR-OR and AND-NOR two-level forms |
| 2018-19 | Q1 | (b) | Express `f(A,B,C,D)` in NAND-AND and OR-NAND two-level forms |
| 2019-20 | Q5 | (a) | Design 3-input majority circuit using only NAND gates |
| 2019-20 | Q5 | (b) | Which gates are universal and why? |
| 2019-20 | Q5 | (c) | Verify DeMorgan's theorem (3 var) and distributive law using truth tables |
| 2020-21 | Q3 | (c) | Express `f(A,B,C) = Π(0,2,3,5,7)` using NOR gates |
| 2021-22 | Q2 | (b) | Show circuit diagram of `AB + CDE` using only NAND gates |
| 2022-23 | Q3 | (a) | Define universal gate; prove NAND and NOR are universal |

---

## 🔵 Combinational Circuits — Adders & Subtractors

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q2 | (b) | Design BCD adder-subtractor (selector bit x); explain 9+7 and 9–7 |
| 2017-18 | Q2 | (c) | Design 3-bit CLA circuit; show carries for 3+4 |
| 2018-19 | Q2 | (b) | Design circuit using 4-bit binary adder + XOR for A+1, A', A'+1, A based on 2-bit select |
| 2018-19 | Q2 | (c) | Design circuit using 4-bit binary adder that computes A×B (3-bit numbers) |
| 2019-20 | Q8 | (a) | Design full-subtractor with inputs x, y, Bin; outputs Diff and Bout |
| 2020-21 | Q4 | (c) | Design 4-bit CLA adder for X3X2X1X0 + Y3Y2Y1Y0; explain roles of carries |
| 2020-21 | Q4 | (b) | Design BCD adder-subtractor with two 4-bit BCD inputs; selector bit S |
| 2021-22 | Q2 | (d) | Steps to find M−N using complement method for n-digit base-r numbers |
| 2022-23 | Q4 | (b) | Design full adder circuit using a 3×8 decoder and two OR gates |
| 2021-22 | Q4 | (a) | Design 4-bit incrementer (adds 1) using only half adders |

---

## 🔵 Combinational Circuits — Comparators & Multipliers

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q2 | (a) | Design circuit that takes two 3-bit numbers X, Y and returns the maximum Z |
| 2018-19 | Q2 | (a) | Design circuit that returns the smaller of two 4-bit binary numbers A and B; demo with A=7, B=9 |
| 2020-21 | Q4 | (a) | Design circuit finding maximum between two 3-bit numbers; demo with 7 and 3 |
| 2021-22 | Q4 | (c) | Design 2-bit × 2-bit binary multiplier |

---

## 🔵 Multiplexers (MUX)

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q4 | (b) | Use 8×1 MUX to implement `f(w,x,y,z) = POS(0,2,5,6,7,8,9,10)`; active-low enable |
| 2017-18 | Q4 | (c) | Design 1-bit Full Adder using two 4×1 MUXes |
| 2018-19 | Q4 | (b) | Use 4×1 MUX to implement `f(w,x,y,z) = Π(0,2,5,6,7,8,9,10)` |
| 2018-19 | Q4 | (c) | Design 1-bit Full Subtractor using 4×1 MUX |
| 2019-20 | Q8 | (b) | Implement `F(A,B,C,D)` with 4×1 MUX; A,B as select lines; derive C,D functions |
| 2020-21 | Q3 | (a) | Design multiplexing circuit for 16 question choices using a switch with 2-bit code |
| 2020-21 | Q3 | (b) | Design digital ticketing system (16 turnstile gates) using a 4-input switch |
| 2022-23 | Q1 | (c) | Implement `F(A,B,C,D) = Σ(1,2,4,7,8,9,10,11,13,15)` with 4×1 MUX and external gates |
| 2021-22 | Q3 | (b) | Determine output function F(X,Y,Z) in POS form from a given MUX figure |

---

## 🔵 Decoders & Encoders

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q3 | (a) | Use 2×4 decoder (active-low outputs) to design logic circuit for `f(w,x,y,z)` SOP |
| 2017-18 | Q3 | (b) | Design 8-to-3 priority encoder with priority order 6,0,7,4,5,3,1,2 |
| 2017-18 | Q3 | (c) | Use 2-to-4 decoder to design half subtractor (active-high outputs) |
| 2018-19 | Q3 | (a) | Use 2-4 decoder (dual active-low enables) to implement `f(w,x,y,z)` |
| 2018-19 | Q3 | (b) | Design 8-to-3 priority encoder with priority order 5,0,7,4,6,3,2,1 |
| 2018-19 | Q3 | (c) | Show how a decoder can function as a demultiplexer |
| 2020-21 | Q1 | (a) | Use 2-4 decoder (active-low outputs, dual enables) to find sum of two 2-bit numbers |
| 2020-21 | Q1 | (b) | Design 8-to-3 priority encoder with priority order B,A,D,E,F,H,G,C |
| 2020-21 | Q1 | (c) | Can a decoder act as a demultiplexer? Explain |
| 2021-22 | Q4 | (b) | Implement `F(x,y,z) = Σ(3,5,6,7)` using active-low 3×8 decoder and AND gates |
| 2021-22 | Q3 | (c) | What is a demultiplexer? Give an example |

---

## 🔵 PLA (Programmable Logic Array)

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2018-19 | Q1 | (a) | Design security lock using PLA for 4 output functions A,B,C,D of 3 inputs |
| 2019-20 | Q4 | (a) | Design circuit using PLA for functions A(x,y,z) and B(x,y,z) |
| 2020-21 | Q2 | (a) | Design digital security lock using PLA for BCD-to-Excess-3 conversion |
| 2021-22 | Q3 | (a) | Tabulate PLA programming table for two 3-input Boolean functions; minimize product terms |
| 2022-23 | Q2 | (b) | Tabulate PLA programming for `F1(A,B,C) = Σ(0,1,2,4)` and `F2(A,B,C) = Σ(0,5,6,7)` |

---

## 🔵 Flip-Flops & Latches

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q5 | (d) | Why are master-slave flip-flops used? |
| 2018-19 | Q5 | (b) | Draw master-slave JK flip-flop using only NAND gates |
| 2018-19 | Q7 | (c) | Why does S=R=1 lead to unstable condition in SR latch? |
| 2019-20 | Q1 | (a) | Design a D flip-flop using a T flip-flop and gates |
| 2020-21 | Q6 | (c) | Design a D flip-flop using a T flip-flop and gates |
| 2021-22 | Q5 | (b) | Construct JK flip-flop from T flip-flop and gates; show all steps |
| 2022-23 | Q5 | (b) | Construct JK flip-flop from T flip-flop and gates |
| 2022-23 | Q6 | (a) | Draw block diagram of negative-edge-triggered Master-Slave D flip-flop using D latches |
| 2021-22 | Q5 | (c) | Draw master-slave JK flip-flop with async preset and clear using only NOR gates |

---

## 🔵 Counters

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q5 | (c) | Use D flip-flops to generate 50 MHz and 25 MHz from 100 MHz clock; draw timing diagram |
| 2018-19 | Q5 | (c) | Design BCD ripple down counter using D flip-flops |
| 2019-20 | Q3 | (a) | Design MOD-12 ripple counter with positive-edge-triggered JK flip-flops |
| 2020-21 | Q5 | (c) | Design BCD ripple down counter using D flip-flops |
| 2017-18 | Q8 | (c) | Design 4-bit modulo-12 asynchronous up counter using JK flip-flops |
| 2021-22 | Q6 | (c) | Design MOD-13 ripple up/down counter with positive-edge JK flip-flops |
| 2022-23 | Q7 | (a) | Show logic diagram of 4-bit binary ripple countdown counter using T flip-flops (negative edge) |
| 2022-23 | Q7 | (b) | Design synchronous counter for sequence 1,2,5,7,1,2,… using JK flip-flops; analyze unused states |
| 2021-22 | Q5 | (a) | Design synchronous counter for sequence 0→2→4→7→5→3→0 using one JK, one T, one D flip-flop |

---

## 🔵 Shift Registers

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q7 | (c) | Design 5-bit ring counter using shift register; draw timing diagram |
| 2018-19 | Q6 | (c) | Design 4-bit Johnson counter using shift register; draw timing diagram |
| 2019-20 | Q2 | (a) | Design 5-bit ring counter and 5-bit Johnson counter; compare and illustrate with timing diagrams |
| 2020-21 | Q5 | (b) | Design 5-bit ring counter and 5-bit Johnson counter; draw timing diagrams |
| 2022-23 | Q6 | (b) | Short note on ring counter |
| 2021-22 | Q5 | (b) | Use 2-to-4 decoder and D flip-flops to design 4-bit shift register with shift-left, shift-right, clear, and parallel-load modes |
| 2022-23 | Q5 | (c) | Design sequential circuit to copy content of shift register A to shift register B |

---

## 🔵 Synchronous Sequential Circuits

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q5 | (a) | Design synchronous counter for sequence 0→1→2→5→4→6→0 using SR flip-flops |
| 2018-19 | Q5 | (a) | Design sequence recognizer for **1101** (overlapping) using SR flip-flops |
| 2019-20 | Q1 | (b) | Design sequence recognizer for 4-bit non-overlapping sequence using T flip-flops |
| 2019-20 | Q2 | (b) | Given JK flip-flop equations, derive transition table, excitation table, state table, and state diagram |
| 2020-21 | Q5 | (a) | Design synchronous counter for sequence 0→2→4→7→5→3→0 using SR flip-flops |
| 2021-22 | Q7 | (a) | Given JK flip-flop equations, draw logic diagram; derive transition/excitation/state table and state diagram |
| 2022-23 | Q5 | (a) | Design sequential circuit that detects three or more consecutive 1s using D flip-flops; show state diagram and state table |
| 2018-19 | Q6 | (a) | Design digital lock circuit using T latches; opening sequence AABABA; bell on incorrect A use |

---

## 🔵 Asynchronous Sequential Circuits — Fundamental Mode

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q8 | (a) | Construct primitive flow table for circuit with sequence 00→01→11; find minimum row-reduced flow table |
| 2017-18 | Q8 | (b) | Find valid race-free state assignment for given reduced flow table; complete modified flow table |
| 2018-19 | Q8 | (a) | Construct primitive flow table for circuit where Z=1 when x1=0 and x2 changes 0→1 or x1=1 and x2 changes 1→0; reduce flow table |
| 2018-19 | Q8 | (b) | Find race-free assignment for given reduced flow table; complete modified flow table |
| 2019-20 | Q4 | (b) | Design fundamental mode electrical lock: X1 on then off while X2=0, then X2 on → Z=1; derive primitive table, reduced table, assignment, K-maps, circuit |
| 2020-21 | Q8 | (a) | Design 2-input 1-output fundamental mode circuit: output changes 0→1 on first x1 change after x2 change; 1→0 when x1=1→0 and x2=1 |
| 2020-21 | Q8 | (b) | Find race-free assignment for given 3-row reduced flow table; complete modified flow table |
| 2021-22 | Q8 | (a) | Construct primitive flow table for traffic light circuit at railroad junction; reduce it |
| 2021-22 | Q8 | (b) | Find race-free assignment for given reduced flow table; complete modified flow table |
| 2022-23 | Q8 | (a) | Define race in fundamental mode; explain critical vs non-critical races with examples |
| 2022-23 | Q8 | (b) | Given excitation and output functions of asynchronous circuit, draw logic diagram; derive transition table and two-state flow table |

---

## 🔵 State Minimization

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q7 | (a) | Find equivalence partitions of a completely specified machine; write state table of minimal machine |
| 2017-18 | Q7 | (b) | Use implication table for incompletely specified machine; find maximal compatibles/incompatibles; upper/lower bounds; minimal machine state table |
| 2018-19 | Q7 | (a) | Use implication table for incompletely specified machine; find maximal compatibles/incompatibles and minimal machine |
| 2018-19 | Q7 | (b) | Find equivalent partitions of completely specified machine; write minimal machine state table |
| 2019-20 | Q3 | (b) | Use implication table for incompletely specified machine; find maximal compatibles and minimal machine |
| 2020-21 | Q7 | (a) | Find equivalence partitions of completely specified 8-state machine; write minimal machine state table |
| 2020-21 | Q7 | (b) | Use implication table for incompletely specified machine with two outputs Z1Z2; find maximal compatibles and minimal machine |
| 2021-22 | Q7 | (b) | Use implication table for incompletely specified 5-state machine; find maximal compatibles and minimal machine |
| 2022-23 | Q8 | (c) | Reduce 5-state completely specified machine using implication table; show reduced state table |

---

## 🔵 Mealy & Moore Machines

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2018-19 | Q6 | (c) | Define Mealy machine and Moore machine |
| 2018-19 | Q8 | (c) | Obtain Mealy equivalent state table for a given Moore machine |
| 2021-22 | Q8 | (c) | Transform given Mealy machine into a corresponding Moore machine |
| 2022-23 | Q7 | (c) | Differentiate Mealy and Moore machines with block diagrams |

---

## 🔵 Vending Machine Design

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q6 | (a) | Design pulse-mode vending machine (candy = 3 Tk; accepts 1 Tk and 2 Tk) using SR flip-flops |
| 2020-21 | Q6 | (a) | Design synchronous vending machine (drink = 20 Tk; accepts 5, 10, 20 Tk; change output) using JK flip-flops |
| 2022-23 | Q6 | (c) | Design pulse-mode vending machine (candy = 15 Tk; accepts 5 Tk and 10 Tk) using SR latches |

---

## 🔵 Parity Circuits

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q4 | (a) | Design odd parity checker and odd parity generator for 3-bit Excess-3 code |
| 2018-19 | Q4 | (a) | Explain difference between odd parity checker and odd parity generator |
| 2019-20 | Q2 | (b) | Design serial parity generation circuit (output 0 for even parity, 1 for odd parity) |
| 2020-21 | Q2 | (c) | Design error-detection circuit for 3-bit data transmission using odd parity |
| 2020-21 | Q6 | (b) | Design serial parity generation circuit |

---

## 🔵 Miscellaneous / Definitions

| Year | Q# | Part | Description |
|------|----|------|-------------|
| 2017-18 | Q1 | (a) | Rules of subtraction for n-digit numbers in base r (M≥N and M<N); compute 9−6.9−9.8 in hex using complement |
| 2022-23 | Q1 | (a) | Steps to find M−N using r-1's complement for n-digit unsigned numbers in base r |
| 2022-23 | Q1 | (b) | Difference between binary and gray encoding; benefits of each |
| 2022-23 | Q2 | (a) | Design combinational circuit converting 3-bit gray code to 3-bit binary; minimum gates |
| 2021-22 | Q1 | (a) | Design combinational circuit converting "Random Code" to BCD using K-Map |
| 2021-22 | Q2 | (c) | Express Boolean function F(A,B,C) = A + B'C as sum of minterms |
| 2018-19 | Q6 | (b) | Design serial adder for two 4-bit numbers A and B stored in shift registers |
| 2021-22 | Q6 | (b) | Design serial subtractor for A−B using JK flip-flops |

---

*Last updated: 2026 | Source: CSE 205 Final Exam Papers, 2017-18 through 2022-23*
