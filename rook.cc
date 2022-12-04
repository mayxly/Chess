#include "rook.h"
using namespace std;

Rook::Rook(std::string colour) : Piece{colour, "rook"} {}

std::vector<Position> Rook::getMoves(Position curpos) {
    vector<Position> moves;
    int row = curpos.x;
    int col = curpos.y;
    Position m1;
    for (int i = row; i < 8; ++i) {
        m1.x = i;
        m1.y = col;
        moves.emplace_back(m1);
    }
    for (int i = row; i >= 0; --i) {
        m1.x = i;
        m1.y = col;
        moves.emplace_back(m1);
    }
    for (int i = col; i < 8; ++i)
    {
        m1.x = row;
        m1.y = i;
        moves.emplace_back(m1);
    }
    for (int i = col; i >= 0; --i)
    {
        m1.x = row;
        m1.y = i;
        moves.emplace_back(m1);
    }
    moves = remove(moves);
    return moves;
} 

    Rook::~Rook() {}
