#include "bishop.h"
using namespace std;

Bishop::Bishop(std::string colour) : Piece{colour, "bishop"} {}

Piece* Bishop::clone() {
    Piece *newB = new Bishop{getColour()};
    if (gethasMoved()) {
        newB->setHasMoved(true);
    }
    return newB;
}

std::vector<Position> Bishop::getMoves(Position curpos) {
    vector<Position> moves;
    int row = curpos.x;
    int col = curpos.y;
    Position m1, m2, m3, m4;
    for (int i =0; i < 8; i++) {
        m1.x = row + i;
        m1.y = col + i;
        m2.x = row - i;
        m2.y = col - i;
        m3.x = row - i;
        m3.y = col + i;
        m4.x = row + i;
        m4.y = col - i;
        moves.emplace_back(m1);
        moves.emplace_back(m2);
        moves.emplace_back(m3);
        moves.emplace_back(m4);
    }
    moves = remove(moves);
    return moves;
}

Bishop::~Bishop() {}
