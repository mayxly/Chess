#ifndef GAME_H
#define GAME_H

#include "display.h"
#include "board.h"
#include "player.h"
class Game {
private:
//  Display *theDisplay;
 Board *theBoard;
 Player *player1;
 Player *player2;
 int turn;
 int p1score;
 int p2score;

public:
 Game();
};

#endif
