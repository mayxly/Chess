#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

#include "square.h"
#include "piece.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"

class Board {
public:
 std::vector<std::vector<Square*>> board; // make the board of all 64 squares     

public:
 Board(std::string type);
 void addPiece(int x, int y, Piece *p);
 Square& getSquare(int x, int y);
};

#endif
