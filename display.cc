#include <iostream>
#include "display.h"
using namespace std;

Display::~Display() {}

void Display::printBoard(Board *b) {
    int rowNum = 8;
    int colour = 1;
    for (int i = 0; i < 8; i++)
    {
        cout << rowNum << " |";
        rowNum--;
        for (int j = 0; j < 8; j++)
        {
            if (colour % 2 == 0) {
                cout << "_";
            } else {
                cout << " ";
            }
            colour++;
        }
        colour++;
        cout << "|" << endl;
    }
}

