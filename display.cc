#include <iostream>
#include "display.h"
using namespace std;

Display::~Display() {}

void Display::printBoard(Board *b)
{
    int rowNum = 8;
    for (int i = 0; i < 8; i++)
    {
        cout << rowNum << " |";
        rowNum--;
        for (int j = 0; j < 8; j++)
        {
            printSquare(i, j, b->getSquare(i, j));
        }
        cout << "|" << endl;
    }
}

void Display::printSquare(int x, int y, Square s)
{
    Piece *p = s.getPiece();
    if (p == nullptr)
    {
        if ((x + y) % 2 == 0) {
            cout << '_';
        } else {
            cout << ' ';
        }
    }
    else
    {
        string type = p->getType();
        char piece;
        if (type == "pawn") {
            piece = 'p';
        } else if (type == "bishop") {
            piece = 'b';
        } else if (type == "rook") {
            piece = 'r';
        } else if (type == "knight") {
            piece = 'n';
        } else if (type == "queen") {
            piece = 'q';
        } else if (type == "king") {
            piece = 'k';
        }

        //Capitalize
        string colour = p->getColour();
        if (colour == "white")
        {
            piece += 32;
        }
    }
}
