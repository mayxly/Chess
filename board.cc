#include "board.h"
using namespace std;

Board::Board(string type)
{
    if (type == "normal") {
        //ROW 8
        vector<Square*> row8{
            new Square{0, 0, new Rook{"black"}},
            new Square{0, 1, new Knight{"black"}},
            new Square{0, 2, new Bishop{"black"}},
            new Square{0, 3, new Queen{"black"}},
            new Square{0, 4, new King{"black"}},
            new Square{0, 5, new Bishop{"black"}},
            new Square{0, 6, new Knight{"black"}},
            new Square{0, 7, new Rook{"black"}},
        };
        board.push_back(row8);

        //ROW 7
        vector<Square*> row7;
        for (int i = 0; i < 8; i++)
        {
            row7.push_back(new Square{1, i, new Pawn{"black"}});
        }
        board.push_back(row7);

        //ROW 6-3
        for (int i = 2; i < 6; i++)
        {
            vector<Square*> row;
            for (int j = 0; j < 8; j++)
            {
                row.push_back(new Square{i, j});
            }
            board.push_back(row);
        }

        //ROW 2
        vector<Square*> row2;
        for (int i = 0; i < 8; i++)
        {
            row2.push_back(new Square{1, i, new Pawn{"white"}});
        }
        board.push_back(row2);

        //ROW 1
        vector<Square*> row1{
            new Square{7, 0, new Rook{"white"}},
            new Square{7, 1, new Knight{"white"}},
            new Square{7, 2, new Bishop{"white"}},
            new Square{7, 3, new Queen{"white"}},
            new Square{7, 4, new King{"white"}},
            new Square{7, 5, new Bishop{"white"}},
            new Square{7, 6, new Knight{"white"}},
            new Square{7, 7, new Rook{"white"}},
        };
        board.push_back(row1);
    }
    else //type == "setup"
    {
        for (int i = 0; i < 8; i++)
        {
            vector<Square*> row;
            for (int j = 0; j < 8; j++)
            {
                row.push_back(new Square{i, j});
            }
            board.push_back(row);
        }
    }
}

// void Board::addPiece(int x, int y, Piece *p)
// {
//     board[x][y].addPiece(p);
// }

Square& Board::getSquare(int x, int y) {
    return *board[x][y];
}
