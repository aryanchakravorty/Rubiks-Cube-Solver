#include "Scrambler.h"
#include <random>

std::vector<std::string> Scrambler::generateScramble(int length) {
    static const std::vector<std::string> baseMoves = {
        "U","D","L","R","F","B"
    };
    static const std::vector<std::string> modifiers = {
        "", "'", "2"
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::string> scramble;
    char lastMove = '\0';

    for (int i = 0; i < length; i++) {
        std::string move;
        do {
            move = baseMoves[gen() % baseMoves.size()];
        } while (move[0] == lastMove);

        lastMove = move[0];
        move += modifiers[gen() % modifiers.size()];
        scramble.push_back(move);
    }

    return scramble;
}
