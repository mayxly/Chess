#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
private:
 std::string colour;
 std::string type;

public:
 King(std::string colour);
};

#endif
