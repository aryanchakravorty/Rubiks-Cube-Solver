# **Optimized Rubik's Cube Solver**

## **Overview**

This project addresses the problem of solving a 3x3x3 Rubik's Cube in the minimum number of moves. It models the physical cube using low-level data structures and employs an **Iterative Deepening Depth-First Search (IDDFS)** algorithm to explore the state space. The solver is highly optimized using move pruning techniques to eliminate redundant searches and utilizes integer-based arithmetic for maximum performance.

## **Input Format**

The solver currently operates on internally generated scrambles.  
To modify the input configuration, update the main.cpp file:

* scrambleLength: Integer defining the number of random moves to scramble the cube.  
* maxDepth: Integer defining the maximum search depth for the solver.

## **Output Format**

1. **Scramble Sequence:** The list of moves applied to scramble the cube.  
2. **Cube State:** A 2D text-based visualization of the cube faces.  
3. **Execution Time:** Time taken by the solver in milliseconds.  
4. **Solution:** The sequence of moves found to solve the cube (if found within the depth limit).  
5. **Verification:** A final check indicating if the cube is solved ("YES").

## **Compilation and Execution**

Ensure a C++ compiler (GCC, Clang, or MSVC) supporting C++11 or later is installed.

Run the following command to compile the project with optimizations enabled:

g++ \-O3 \-o cube\_solver main.cpp Cube.cpp Face.cpp Move.cpp Renderer.cpp Scrambler.cpp Solver.cpp

Run the executable:

./cube\_solver

## **Key Components**

### **Algorithms Used**

* **Iterative Deepening DFS (IDDFS):** Explores the search tree layer by layer (Depth 1, Depth 2, etc.) to guarantee that the first solution found is the shortest possible one.  
* **Move Pruning:** Reduces the search space by cutting off redundant branches:  
  * **Redundancy Check:** Prevents turning the same face twice in a row (e.g., U followed by U).  
  * **Commutative Ordering:** Enforces a specific order for independent opposite face turns (e.g., checking U D but skipping D U) to avoid processing identical states.

### **Core Functions**

* solve(int maxDepth): The main entry point that iterates through depths calling DFS.  
* dfs(int depth, ...): The recursive worker function that explores move combinations and backtracks.  
* applyMove(int moveIndex): Optimally applies a move to the cube state using integer mapping (0-17) rather than string parsing.  
* isSolved(): Verifies if the cube state is solved (all faces have uniform colors).  
* generateScramble(int length): Produces a valid random sequence of moves to initialize the cube.  
* printCube(): Renders the unfolded cube state to the console.

## **Idea**

The core idea is to represent the cube state as flat arrays for cache-friendly memory access. Instead of using string-based moves (like "R", "U'"), the engine maps moves to integers (0-17). This allows for $O(1)$ move application and instant inverse lookups during backtracking.

The solver starts at depth 0 and iteratively increases the search depth. At every step of the DFS, it:

1. Checks if the cube is solved.  
2. Generates valid next moves.  
3. **Prunes** moves that reverse the previous move or violate commutative ordering rules.  
4. Recurses to the next depth.

## **Constraints Handled**

* **Optimal Solution:** Guarantees the shortest path to the solved state within the search depth.  
* **Performance:** Minimizes memory allocation by avoiding string operations in the critical path.  
* **State Validity:** Ensures only valid physical moves are applied to the cube model.

## **Output**

Prints the scramble, the visual state, the time taken, and the solution sequence.

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

\============================  
Time taken by solver: 6312 ms

\============================  
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
