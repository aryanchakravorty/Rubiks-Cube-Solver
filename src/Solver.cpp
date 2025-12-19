#include "Solver.h"

Solver::Solver(Cube& cube) : cube(cube) {}

bool Solver::solve(int maxDepth) {
    solution.clear();

    for (int d = 1; d <= maxDepth; d++) {
        if (dfs(0, d, -1)) {
            return true;
        }
    }
    return false;
}

const std::vector<Move>& Solver::getSolution() const {
    return solution;
}

bool Solver::dfs(int depth, int maxDepth, int lastMoveIndex) {
    if (cube.isSolved()) return true;
    if (depth == maxDepth) return false;

    // Try all 18 moves
    for (int i = 0; i < 18; i++) {
        
        // === PRUNING ===
        if (lastMoveIndex != -1) {
            int currentFace = getFace(i);
            int lastFace = getFace(lastMoveIndex);

            if (currentFace == lastFace) continue;

            if ((currentFace / 2) == (lastFace / 2)) {
                if (currentFace < lastFace) continue;
            }
        }

        cube.applyMove(i);
        solution.push_back(Move(moveNames[i]));

        if (dfs(depth + 1, maxDepth, i)) return true;

        solution.pop_back();
        cube.applyMove(inverseMoves[i]);
    }

    return false;
}