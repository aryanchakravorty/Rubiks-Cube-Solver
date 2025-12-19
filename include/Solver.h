#ifndef SOLVER_H
#define SOLVER_H

#include "Cube.h"
#include "Move.h"
#include <vector>
#include <string>

class Solver {
public:
    explicit Solver(Cube& cube);

    // Uses IDDFS to find the shortest solution
    bool solve(int maxDepth);

    const std::vector<Move>& getSolution() const;

private:
    Cube& cube;
    std::vector<Move> solution;

    // Move names mapped to indices 0-17
    const std::vector<std::string> moveNames = {
        "U", "U'", "U2",
        "D", "D'", "D2",
        "L", "L'", "L2",
        "R", "R'", "R2",
        "F", "F'", "F2",
        "B", "B'", "B2"
    };

    // Fast inverse lookup for undoing moves
    const int inverseMoves[18] = {
        1, 0, 2,   // U
        4, 3, 5,   // D
        7, 6, 8,   // L
        10, 9, 11, // R
        13, 12, 14,// F
        16, 15, 17 // B
    };

    // Helper: Maps move index (0-17) to face index (0-5)
    int getFace(int moveIndex) const {
        return moveIndex / 3;
    }

    // Depth-limited DFS with pruning
    bool dfs(int depth, int maxDepth, int lastMoveIndex);
};

#endif