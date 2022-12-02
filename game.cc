#include "game.h"
#include "human.h"
#include "player.h"
// #include "computer.h"
#include <iostream>
using namespace std;

Game::Game(Display *d) : display{d} {}

void Game::play() {
    display->printMsg("Play a normal game\tgame <human/computer> <human/computer>\nStart setup mode\tsetup\n");
    string command;
    cin >> command;
    while(true) {
        if (command == "game") {
            board = new Board{"normal"};
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
                // player1 = new Computer{level};
            }
            cin >> b_player;
        }
        else if (command == "setup") {
            board = new Board{"setup"};
            setup();
        }
        else {
            display->printMsg("Error invalid command, please try again!");
            continue;
        }
    }
    display->printMsg("Welcome to Chess!");
    display->printBoard(board);
}


void Game::setup() {
    display->printMsg("\nAdd piece\t\t+ <Piece> <Square>");
    display->printMsg("Remove piece\t\t- <Square>");
    display->printMsg("Set next colour\t\t= <Colour>");
    display->printMsg("Finish setup\t\tdone\n");
    string cmd;
    string colour;
    string square;
    char piece;
    while (1) {
        cin >> cmd;
        if (cmd == "done") {
            break;
        } 
        else if (cmd == "+") {
            cin >> piece;
            cin >> square;
            addPiece(piece, square);
            display->printBoard(board);
        }
        else if (cmd == "-") {
            cin >> square;
            removePiece(square);
            display->printBoard(board); 
        } 
        else if (cmd == "=") {
            cin >> colour;
            if (colour == "white") {
                turn = 1;
            } else {
                turn = 2;
            }
        } 
    }
}

void Game::addPiece(char piece, string square) {
    //Find the x,y coordinates
    int x = abs((square[1] - '1')-7);
    int y = square[0] - 'a';

    //Find the piece & colour
    string colour;
    if (piece >= 'a' && piece <= 'z') {
        colour = "black";
        piece += ('A' - 'a');
    } else {
        colour = "white";
    }

    //Add the piece
    if (piece == 'K') {
        King *k = new King{colour};
        board->getSquare(x, y).setPiece(k);
    }
    else if (piece == 'Q') {
        Queen *q = new Queen{colour};
        board->getSquare(x, y).setPiece(q);
    }
    else if (piece == 'N') {
        Knight *n = new Knight{colour};
        board->getSquare(x, y).setPiece(n);
    }
    else if (piece == 'R') {
        Rook *r = new Rook{colour};
        board->getSquare(x, y).setPiece(r);
    }
    else if (piece == 'B') {
        Bishop *b = new Bishop{colour};
        board->getSquare(x, y).setPiece(b);
    }
    else if (piece == 'P') {
        Pawn *p = new Pawn{colour};
        board->getSquare(x, y).setPiece(p);
    }
}


void Game::removePiece(string square) {
    int x = abs((square[1] - '1')-7);
    int y = square[0] - 'a';
    board->getSquare(x, y).setPiece(nullptr);
}
    


