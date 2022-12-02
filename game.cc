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
    display->printMsg("To start playing enter: game <human/computer[level 1-4+]> <human/computer[level 1-4+]> otherwise enter: setup");
    string command;
    cin >> command;
    while(true) {
        if (command == "game") {
            string name1;
            string name2;
            string w_player;
            string b_player;
            cin >> w_player;
            cin >> b_player;
            display->printMsg("Enter player1's name:");
            cin >> name1;
            if (w_player == "human") {
                player1 = new Human{"white", name1};
            } else if (w_player.substr(0,8) == "computer") {
                char levl = w_player[9];
                int level = levl - '0';
                player1 = new Computer{level, "white", name1};
                break;
            }
            display->printMsg("Enter player2's name:");
            cin >> name2;
            if (b_player == "human")
            {
                player1 = new Human{"white", name2};
            }
            else if (b_player == "computer")
            {
                char levl = w_player[9];
                int level = levl - '0';
                player1 = new Computer{level, "white", name2};
                break;
            }
        }
        else if (command == "setup") {
            continue;
        }
        else {
            display->printMsg("Error invalid command, please try again!");
            continue;
        }
    }
    display->printMsg("Welcome to Chess!");
    display->printBoard(board);
}

