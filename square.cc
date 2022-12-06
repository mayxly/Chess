#include "square.h"
using namespace std;

Square::Square(int x, int y, Piece *piece) : piece{piece}
 { 
    Position p{x, y};
    position = p;
 }

//  Square::~Square() {
//    delete piece;
//  }

void Square::setPiece(Piece *piece) {
   this->piece = piece;
}

Piece* Square::getPiece() {
   return piece;
}

Position Square::getPosition() {
   return position;
}