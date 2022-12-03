#ifndef MOVE_H
#define MOVE_H

#include <vector>

#include "board.h"
#include "square.h"
#include "piece.h"

class Move {
protected:
    Board *board;
    Position cur;
    Position dest;
    std::string colour;

public:
    Move(Board* b, Position cur, Position dest, std::string colour);
};

#endif