#include "square.h"
using namespace std;

Square::Square(int x, int y, Piece *piece) : piece{piece}
 { 
    Position p{x, y};
    position = p;
 }

