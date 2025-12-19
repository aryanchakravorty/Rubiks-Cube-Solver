#include "Move.h"
#include <stdexcept>
#include <string>

Move::Move(const std::string& notation) {
    if (notation.empty())
        throw std::invalid_argument("Empty move");

    switch (notation[0]) {
        case 'U': type = MoveType::U; break;
        case 'D': type = MoveType::D; break;
        case 'L': type = MoveType::L; break;
        case 'R': type = MoveType::R; break;
        case 'F': type = MoveType::F; break;
        case 'B': type = MoveType::B; break;
        default:
            throw std::invalid_argument("Invalid move type");
    }

    if (notation.size() == 1) {
        turns = 1;
    } else if (notation[1] == '2') {
        turns = 2;
    } else if (notation[1] == '\'') {
        turns = 3;
    } else {
        throw std::invalid_argument("Invalid move modifier");
    }
}

MoveType Move::getType() const {
    return type;
}

int Move::getTurns() const {
    return turns;
}

std::string Move::toString() const {
    char c;

    switch (type) {
        case MoveType::U: c = 'U'; break;
        case MoveType::D: c = 'D'; break;
        case MoveType::L: c = 'L'; break;
        case MoveType::R: c = 'R'; break;
        case MoveType::F: c = 'F'; break;
        case MoveType::B: c = 'B'; break;
        default:          c = '?'; break; 
    }

    if (turns == 1) return std::string(1, c);
    if (turns == 2) return std::string(1, c) + "2";
    return std::string(1, c) + "'";
}

