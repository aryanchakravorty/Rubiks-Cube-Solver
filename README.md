# Optimized Rubik's Cube Solver (C++)

## Overview

This project solves a **3×3×3 Rubik's Cube** in the minimum number of moves.
It models the physical cube using low-level data structures and employs an
**Iterative Deepening Depth-First Search (IDDFS)** algorithm to explore the state space.

The solver is optimized using aggressive move pruning and integer-based state
representation, avoiding expensive string operations for better performance.

---

## Input Format

The solver currently operates on **internally generated scrambles**.

To modify the input configuration, edit `main.cpp`:

* **scrambleLength**
  Integer defining the number of random moves used to scramble the cube.

* **maxDepth**
  Integer defining the maximum depth searched by the solver.

---

## Output Format

The program produces the following output:

1. **Scramble Sequence** – the list of moves applied to scramble the cube.
2. **Cube State** – a 2D text-based visualization of the cube.
3. **Execution Time** – time taken by the solver in milliseconds.
4. **Solution** – the sequence of moves used to solve the cube.
5. **Verification** – final confirmation indicating whether the cube is solved.

---

## Compilation and Execution

### Requirements

* C++ compiler (GCC, Clang, or MSVC)
* C++11 or later

### Compile

```bash
g++ -O3 -o cube_solver \
    main.cpp Cube.cpp Face.cpp Move.cpp Renderer.cpp Scrambler.cpp Solver.cpp
```

### Run

```bash
./cube_solver
```

---

## Key Components

### Algorithms Used

* **Iterative Deepening DFS (IDDFS)**
  Searches the state space depth by depth, guaranteeing the shortest solution
  when one is found.

* **Move Pruning**
  Reduces the search space by eliminating redundant branches:

  * Prevents applying the same face move consecutively (e.g., `U` followed by `U`).
  * Enforces a fixed order for opposite face moves (e.g., explores `U D` but skips `D U`).

---

## Core Functions

* `solve(int maxDepth)`
  Entry point that iterates over increasing depth limits and invokes DFS.

* `dfs(int depth, ...)`
  Recursive search function that explores valid move sequences and backtracks.

* `applyMove(int moveIndex)`
  Applies a move using integer mapping (`0–17`) instead of string parsing.

* `isSolved()`
  Checks whether all cube faces contain uniform colors.

* `generateScramble(int length)`
  Generates a valid random scramble sequence.

* `printCube()`
  Prints the unfolded cube state to the console.

---

## Idea

The cube state is represented using **flat arrays** for cache-friendly memory access.
Moves are mapped to integers (`0–17`) rather than strings, enabling constant-time
move application and fast inverse lookups.

The solver starts at depth `0` and incrementally increases the search depth. At each
DFS step, it:

1. Checks whether the cube is solved.
2. Generates valid next moves.
3. Prunes moves that reverse the previous move or violate ordering rules.
4. Recursively explores the next depth level.

---

## Constraints Handled

* **Optimal Solution**
  Guarantees the shortest solution within the specified search depth.

* **Performance**
  Minimizes memory allocation and avoids string operations in the critical path.

* **State Validity**
  Ensures only physically valid cube moves are applied.

---

## Sample Output

```text
Scramble moves:
L U2 L B2 D U L2

Scrambled cube:
      B Y Y
      W W Y
      Y B W
W G G O O O G B B R O O
R O R B G G R R O G B W
Y B W R O R W G G R R O
      G W B
      W Y Y
      B Y Y

============================
Time taken by solver: 6312 ms
============================

Solution FOUND within depth 7
Solution moves:
L2 U' D' B2 L' U2 L'

Cube after solver:
      W W W
      W W W
      W W W
O O O G G G R R R B B B
O O O G G G R R R B B B
O O O G G G R R R B B B
      Y Y Y
      Y Y Y
      Y Y Y

Cube solved? YES
```

---


