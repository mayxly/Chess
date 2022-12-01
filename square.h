#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"

struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0) : x{x}, y{y} {}
};

class Square {
private:
 Position position;
//  Piece *piece;
std::string piece;

public:
//  Square(int x, int y, Piece *piece = nullptr);
 Square(int x, int y, std::string piece);
};

#endif
