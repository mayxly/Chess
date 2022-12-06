#ifndef MOVE_H
#define MOVE_H

#include <vector>

#include "board.h"
#include "square.h"
#include "piece.h"

class Move {
protected:
    Board *board;
    Position start;
    Position end;
    std::string colour;

public:
    Move(Board* b, Position start, Position end, std::string colour);
    //virtual Board movePiece(std::string promoteTo = 0); 
    bool isValid();
    bool isValidPath();
    std::string getMoveType();
    bool isEnpassant();
    bool isPromotepawn();
    bool isCastle();
    bool isNormalKill();
    bool isKingSafe();
};

#endif