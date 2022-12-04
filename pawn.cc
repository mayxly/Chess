#include "pawn.h"
using namespace std;

Pawn::Pawn(std::string colour) : Piece{colour, "pawn"} {}

std::vector<Position> Pawn::getCaptureMoves(Position curpos) {
    vector<Position> moves;
    int row = curpos.x;
    int col = curpos.y;
    Position m1, m2;

    if (getColour() == "black") {
       if (row != 7) {
           m1.x = row + 1;
           m1.y = col + 1;
           m2.x = row + 1;
           m2.y = col - 1;
           moves.emplace_back(m1);
           moves.emplace_back(m2);
       }
    } else {
        if (row != 0) {
            m1.x = row - 1;
            m1.y = col + 1;
            m2.x = row - 1;
            m2.y = col - 1;
            moves.emplace_back(m1);
            moves.emplace_back(m2);
        }
    }
    moves = remove(moves);
    return moves;
}

std::vector<Position> Pawn::getMoves(Position curpos) {
    vector<Position> moves;
    int row = curpos.x;
    int col = curpos.y;
    Position m1, m2;
    if (getColour() == "black") {
        m1.x = row+1;
        m1.y = col;
        moves.emplace_back(m1);
        if (!gethasMoved()) {
            m2.x = row+2;
            m2.y = col;
            moves.emplace_back(m2);
        }
    } else if (getColour() == "white") {
        m1.x = row - 1;
        m1.y = col;
        moves.emplace_back(m1);
        if (!gethasMoved())
        {
            m2.x = row - 2;
            m2.y = col;
            moves.emplace_back(m2);
        }
    }
    moves = remove(moves);
    return moves;
}

    Pawn::~Pawn() {}
