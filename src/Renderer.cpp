#include "Renderer.h"
#include <iostream>

static char colorToChar(Color c) {
    switch (c) {
        case Color::White: return 'W';
        case Color::Yellow: return 'Y';
        case Color::Red: return 'R';
        case Color::Orange: return 'O';
        case Color::Blue: return 'B';
        case Color::Green: return 'G';
    }
    return '?';
}

static void printFaceRow(const Face& face, int row) {
    for (int i = 0; i < 3; i++) {
        std::cout << colorToChar(face.getSticker(row * 3 + i)) << " ";
    }
}

void Renderer::printCube(const Cube& cube) {
    const Face& U = cube.getFace(0);
    const Face& D = cube.getFace(1);
    const Face& F = cube.getFace(2);
    const Face& B = cube.getFace(3);
    const Face& L = cube.getFace(4);
    const Face& R = cube.getFace(5);

    // UP
    for (int r = 0; r < 3; r++) {
        std::cout << "      ";
        printFaceRow(U, r);
        std::cout << "\n";
    }

    // LEFT FRONT RIGHT BACK
    for (int r = 0; r < 3; r++) {
        printFaceRow(L, r);
        printFaceRow(F, r);
        printFaceRow(R, r);
        printFaceRow(B, r);
        std::cout << "\n";
    }

    // DOWN
    for (int r = 0; r < 3; r++) {
        std::cout << "      ";
        printFaceRow(D, r);
        std::cout << "\n";
    }
}
