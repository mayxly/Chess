#include "board.h"
#include "move.h"
#include <iostream>
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
    Position p{-1, -1};
    recentPawnPos = p;
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
    }
}


Square& Board::getSquare(int x, int y) {
    return *board[x][y];
}

int Board::isValid() {
    //one white king
    //one black king
    int wKingCount = 0;
    int bKingCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* p = board[i][j]->getPiece();
            if (p) {
                if (p->getColour() == "black" && p->getType() == "king") {
                    bKingCount++;
                }
                if (p->getColour() == "white" && p->getType() == "king") {
                    wKingCount++;
                }
            }
        }
    }
    if (wKingCount > 1 || bKingCount > 1) {
        return 1;
    }


    //no pawns on first or last row of board
    for (int i = 0; i < 8; i++) {
        Piece* p = board[0][i]->getPiece();
        if (p) {
            if (p->getType() == "pawn") {
                return 2;
            }
        }
        p = board[7][i]->getPiece();
        if (p) {
            if (p->getType() == "pawn") {
                return 2;
            }
        }
    }
    //neither king is in check
    if (isCheck("black") || isCheck("white")) {
        return 3;
    }
    return 0;
}

Position Board::getRecentPawnPos() {
    return recentPawnPos;
}

void Board::setRecentPawnPos(Position p) {
    this->recentPawnPos = p;
}

bool Board::isCheck(std::string colour) {
    Position kingPos{0, 0};
    for (int i = 0; i < 8; i++) { //look for your king
		for (int j = 0; j < 8; j++) {
            Piece *p  = board[i][j]->getPiece();
            if (p && p->getType() == "king" && p->getColour() == colour) {
                kingPos.x = i;
                kingPos.y = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) { //look for other opponent pieces
		for (int j = 0; j < 8; j++) {
            Piece *p  = board[i][j]->getPiece();
            if (p && p->getColour() != colour) {
                Board *b = this;
                Move curMove{b, Position{i, j}, kingPos, p->getColour()};
                if (curMove.isValid()) {
                     return true;
                }
            }
        }
    }
    return false;
}


bool Board::isCheckmate(std::string colour) {
    bool movePossible = this->isMovePossible(colour);
    if (movePossible) {
        return false;
    } else {
        if (colour == "white" && isCheck("white")) {
            return true;
        } 
        else if (colour == "black" && isCheck("black")) {
            return true;
        }
    }
    return false;
}

bool Board::isMovePossible(std::string colour) {
    vector <Position> movesPossible;
    for (int i = 0; i < 8; i++) { //check each piece for possible moves to move/kill
		for (int j = 0; j < 8; j++) {
            Piece *p = this->getSquare(i, j).getPiece();
            if (p && p->getColour() == colour) {
                movesPossible =  p->getMoves(Position{i, j});
                if (p->getType() == "pawn") {   //pawn has different capture moves
                    Pawn *pawn = dynamic_cast<Pawn *>(p);
                    vector <Position> killsPossible = pawn->getCaptureMoves(Position{i, j});
                    movesPossible.insert(movesPossible.end(), killsPossible.begin(), killsPossible.end());
                }
                int len = movesPossible.size();
                for (int i = 0; i < len; i++) {
                    Board *b = this;
                    Move curMove{b, Position{i, j}, movesPossible[i], p->getColour()};
                    if (curMove.isValid()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// vector <pair<Position, Position>> Board::getMovesPossible(std::string colour) {
//     for ()
// }

State Board::getState() { //this is incorrect... need stalemate
    if (this->isCheckmate("white")) {
        return State::WhiteCheckmate;
    }
    else if (this->isCheckmate("black")) {
        return State::BlackCheckmate;
    }
    else if (this->isCheck("white")) {
        return State::WhiteCheckmate;
    }
    else if (this->isCheck("black")) {
        return State::BlackCheckmate;
    }
    else {
        return State::Normal;
    }
}