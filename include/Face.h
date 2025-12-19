#ifndef FACE_H
#define FACE_H

#include <array>
#include <iostream>

enum class Color {
    White,
    Yellow,
    Red,
    Orange,
    Blue,
    Green
};

class Face {
public:
    Face(Color initialColor);

    Color getSticker(int index) const;
    void setSticker(int index, Color color);

    // Rotations
    void rotateClockwise();
    void rotateCounterClockwise();

    // Debug / visualization helper
    void print() const;

private:
    std::array<Color, 9> stickers;
};

#endif
