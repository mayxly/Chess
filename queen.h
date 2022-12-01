#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
private:
 std::string colour;
 std::string type;

public:
 Queen(std::string colour);
};

#endif
