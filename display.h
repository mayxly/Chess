#ifndef DISPLAY_H
#define DISPLAY_H
#include "game.h"
#include <string>

class Display {
private:
 Game *game;

public:
 Display(Game *game);
 void printBoard(Board *b);
 void printMsg(std::string msg);
 void printWin(std::string msg);
 ~Display();
};

#endif
