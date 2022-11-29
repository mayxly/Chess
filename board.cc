#include "board.h"
using namespace std;

Board::Board()
{
    for (int i = 0; i < 64; i++)
    {
        vector<Square> row;
        for (int j = 0; j < 64; j++)
        {
            Square s{i, j};
            row.push_back(s);
        }
        theBoard.push_back(row);
    }
}
