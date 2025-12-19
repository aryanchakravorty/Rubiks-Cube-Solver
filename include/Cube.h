#ifndef CUBE_H
#define CUBE_H

#include <array>
#include "Face.h"
#include "Move.h"

class Cube {
public:
    Cube();

    // Basic face rotations
    void moveU();
    void moveD();
    void moveF();
    void moveB();
    void moveL();
    void moveR();

    void applyMove(int moveIndex);

    void applyMove(const Move& move);

    bool isSolved() const;
    const Face& getFace(int index) const;

private:
    std::array<Face, 6> faces;
};

#endif