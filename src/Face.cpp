#include "Face.h"

// Constructor: initialize all stickers with the same color
Face::Face(Color initialColor) {
    stickers.fill(initialColor);
}

// Get sticker at index (0–8)
Color Face::getSticker(int index) const {
    return stickers[index];
}

// Set sticker at index
void Face::setSticker(int index, Color color) {
    stickers[index] = color;
}

// Rotate face 90 degrees clockwise
void Face::rotateClockwise() {
    std::array<Color, 9> old = stickers;

    stickers[0] = old[6];
    stickers[1] = old[3];
    stickers[2] = old[0];
    stickers[3] = old[7];
    stickers[4] = old[4];
    stickers[5] = old[1];
    stickers[6] = old[8];
    stickers[7] = old[5];
    stickers[8] = old[2];
}

// Rotate face 90 degrees counter-clockwise
void Face::rotateCounterClockwise() {
    // Counter-clockwise = 3 clockwise rotations
    rotateClockwise();
    rotateClockwise();
    rotateClockwise();
}

// Print face in 3×3 format (debugging)
void Face::print() const {
    for (int i = 0; i < 9; i++) {
        std::cout << static_cast<int>(stickers[i]) << " ";
        if (i % 3 == 2) std::cout << "\n";
    }
}
