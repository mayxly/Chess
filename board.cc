#include "board.h"
using namespace std;

Board::Board()
{
    //ROW 8
    vector<Square> row8{
        {0, 0, new Rook{"black"}},
        {0, 1, new Knight{"black"}},
        {0, 2, new Bishop{"black"}},
        {0, 3, new Queen{"black"}},
        {0, 4, new King{"black"}},
        {0, 5, new Bishop{"black"}},
        {0, 6, new Knight{"black"}},
        {0, 7, new Rook{"black"}},
    };
    board.push_back(row8);

    //ROW 7
    vector<Square> row7;
    for (int i = 0; i < 8; i++)
    {
        row7.push_back({1, i, new Pawn{"black"}});
    }
    board.push_back(row7);

    //ROW 6-3
    for (int i = 2; i < 6; i++)
    {
        vector<Square> row;
        for (int j = 0; j < 8; j++)
        {
            row.push_back({i, j});
        }
        board.push_back(row);
    }

    //ROW 2
    vector<Square> row2;
    for (int i = 0; i < 8; i++)
    {
        row7.push_back({1, i, new Pawn{"white"}});
    }
    board.push_back(row2);

    //ROW 1
    vector<Square> row1{
        {7, 0, new Rook{"white"}},
        {7, 1, new Knight{"white"}},
        {7, 2, new Bishop{"white"}},
        {7, 3, new Queen{"white"}},
        {7, 4, new King{"white"}},
        {7, 5, new Bishop{"white"}},
        {7, 6, new Knight{"white"}},
        {7, 7, new Rook{"white"}},
    };
    board.push_back(row1);
}
