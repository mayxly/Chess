#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
private:
 std::string colour;
 std::string type;

public:
 Pawn(std::string colour);
};

#endif
