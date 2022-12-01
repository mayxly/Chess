#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece {
private:
 char colour;
 std::string type;

public:
 Piece(char colour, std::string type);
};

#endif
