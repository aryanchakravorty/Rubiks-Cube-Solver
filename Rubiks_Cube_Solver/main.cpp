#include <iostream>
#include <vector>
#include <chrono>

#include "Cube.h"
#include "Move.h"
#include "Scrambler.h"
#include "Renderer.h"
#include "Solver.h"

int main() {
    Cube cube;

    // ============================
    // 1. Scramble the cube
    // ============================
    int scrambleLength = 7;   // keep small for brute force
    auto scramble = Scrambler::generateScramble(scrambleLength);

    std::cout << "Scramble moves:\n";
    for (const auto& m : scramble) {
        std::cout << m << " ";
        cube.applyMove(Move(m));
    }
    std::cout << "\n\nScrambled cube:\n";
    Renderer::printCube(cube);

    // ============================
    // 2. Solve using brute force
    // ============================
    Solver solver(cube);

    int maxDepth = 7;   // IMPORTANT: brute force grows exponentially
    auto start = std::chrono::high_resolution_clock::now();
    bool solved = solver.solve(maxDepth);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n============================\n";
    std::cout << "Time taken by solver: " << duration.count() << " ms\n";

    std::cout << "\n============================\n";
    if (solved) {
        std::cout << "Solution FOUND within depth " << maxDepth << "\n";
        std::cout << "Solution moves:\n";

        for (const auto& m : solver.getSolution()) {
            std::cout <<m.toString()<< " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "No solution found within depth " << maxDepth << "\n";
    }

    // ============================
    // 3. Final cube state
    // ============================
    std::cout << "\nCube after solver:\n";
    Renderer::printCube(cube);

    std::cout << "\nCube solved? "
              << (cube.isSolved() ? "YES" : "NO")
              << "\n";

    return 0;
}
