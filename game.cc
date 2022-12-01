#include "game.h"
#include <iostream>
using namespace std;

Game::Game(Display *d) : display{d} {
    Board *b = new Board{"normal"};
    board = b;
}

void Game::play() {
    cout << "Welcome to Chess!" << endl;
    display->printBoard(board);
}

