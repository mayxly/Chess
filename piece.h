#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece {
private:
 std::string colour;
 std::string type;

public:
 Piece(std::string colour, std::string type);
};

#endif
