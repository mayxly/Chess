#ifndef SQUARE_H
#define SQUARE_H

struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0) : x{x}, y{y} {}
};

class Square {
private:
 Position position;
//  Piece *piece = nullptr;

public:
 Square(int x, int y);
};

#endif
