#include "piece.h"
using namespace std;

Piece::Piece(std::string colour, std::string type) : colour{colour}, type{type} {}

string Piece::getColour() {
    return colour;
}

string Piece::getType() {
    return type;
}

