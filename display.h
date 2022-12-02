#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h"
class Display {
private:

public:
 void printBoard(Board *b);
 void printSquare(int x, int y, Square s);
 void printMsg(std::string msg);
 ~Display();
};

#endif
