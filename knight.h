#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
private:
 std::string colour;
 std::string type;

public:
 Knight(std::string colour);
};

#endif
