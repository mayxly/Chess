#include "board.h"
using namespace std;

//BOARD CONSTRUCTER WITH ALL THE PIECES ON THE BOARD
//Right now it's temporarily adding in strings. It's supposed to add in the pieces

//EXAMPLE

// Piece *w_rook1 = new Rook{};
// vector<Square> row8{
//     {0, 0, w_rook1},    This is line 22
//     {},
//     {},
// }

//Once we add all the piece classes, then make sure to change piece.h and square.h correctly

Board::Board()
{
    //ROW 8
    vector<Square> row8{
        {0, 0, "rook"},
        {0, 1, "knight"},
        {0, 2, "bishop"},
        {0, 3, "queen"},
        {0, 4, "king"},
        {0, 5, "bishop"},
        {0, 6, "knight"},
        {0, 7, "rook"},
    };
    board.push_back(row8);

    //ROW 7
    vector<Square> row7;
    for (int i = 0; i < 8; i++)
    {
        row7.push_back({1, i, "pawn"});
    }
    board.push_back(row7);

    //ROW 6-3
    for (int i = 2; i < 6; i++)
    {
        vector<Square> row;
        for (int j = 0; j < 8; j++)
        {
            row.push_back({i, j, ""});
        }
        board.push_back(row);
    }

    //ROW 2
    vector<Square> row2;
    for (int i = 0; i < 8; i++)
    {
        row7.push_back({6, i, "pawn"});
    }
    board.push_back(row2);

    //ROW 1
    vector<Square> row1{
        {7, 0, "rook"},
        {7, 1, "knight"},
        {7, 2, "bishop"},
        {7, 3, "queen"},
        {7, 4, "king"},
        {7, 5, "bishop"},
        {7, 6, "knight"},
        {7, 7, "rook"},
    };
    board.push_back(row1);

}
