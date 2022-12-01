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
 Piece *piece;
 
public:
 Square(int x, int y, Piece *piece = nullptr);
 void addPiece(Piece *piece);
 Piece* getPiece();
};

#endif
