#ifndef MOVE_H
#define MOVE_H

#include <string>

enum class MoveType {
    U,
    D,
    L,
    R,
    F,
    B
};

class Move {
public:
    explicit Move(const std::string& notation);

    MoveType getType() const;
    int getTurns() const;  // 1 = CW, 2 = 180°, 3 = CCW

    std::string toString() const;

private:
    MoveType type;
    int turns;
};

#endif
