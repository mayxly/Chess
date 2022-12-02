#include "game.h"
#include "human.h"
#include "player.h"
#include "computer.h"
#include <iostream>
using namespace std;

Game::Game(Display *d) : display{d} {
    Board *b = new Board{"normal"};
    board = b;
}

void Game::play() {
    display->printMsg("To start playing enter: game <human/computer> <human/computer> otherwise enter: setup");
    string command;
    cin >> command;
    while(true) {
        if (command == "game") {
            string w_player;
            string b_player;
            cin >> w_player;
            if (w_player == "human") {
                display->printMsg("Enter your name:");
                string name;
                cin >> name;
                player1 = new Human{"white", name};
            } else if (w_player == "computer") {
                display->printMsg("What is the level of the computer?");
                int level;
                cin >> level;
                player1 = new Computer{level};
            }
            cin >> b_player;
        }
        else if (command == "setup") {

        }
        else {
            display->printMsg("Error invalid command, please try again!");
            continue;
        }
    }
    display->printMsg("Welcome to Chess!");
    display->printBoard(board);
}

