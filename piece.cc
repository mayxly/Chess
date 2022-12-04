#include "piece.h"
using namespace std;

Piece::Piece(std::string colour, std::string type) : colour{colour}, type{type} {}

string Piece::getColour() {
    return colour;
}

string Piece::getType() {
    return type;
}

vector<Position> Piece::remove(vector <Position> n) {
    vector <Position> checkedMoves;
    for (auto move: n) {
        int row = move.y;
        int col = move.x;
        if (row <= 7 && row >= 0 && col <= 7 && col <= 0) {
            checkedMoves.emplace_back(move);
        }
    }
    return checkedMoves;
}

bool Piece::gethasMoved() {
    return hasMoved;
}

void Piece::sethasMoved() {
    hasMoved = false;
}

Piece::~Piece() {}
