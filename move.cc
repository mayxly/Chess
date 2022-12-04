#include "move.h"
#include <vector>
using namespace std;

Move::Move(Board* b, Position start, Position end, std::string colour) : board{b}, start{start}, end{end}, colour{colour} {}

bool Move::isValid() {
    Piece *curPiece = board->getSquare(start.x, start.y).getPiece();
    Piece *pieceToKill = board->getSquare(end.x, end.y).getPiece();

    if (start.x == end.x && start.y == end.y) { //start and end are the same
        return false;
    }
    if (!curPiece) { //start pos piece does not exists
        return false;
    }
    if (curPiece->getColour() != colour) { //start pos piece does not belongs to them
        return false;
    }
    if (isValidPath()) {
        // vector <Position> validMoves = curPiece->getMoves(start);
        // int len = validMoves.size();
        if (!pieceToKill) {    //no piece to kill, just move to square
            // for (int i = 0; i < len; i++) {
            //     if (validMoves[i].x == end.x && validMoves[i].y == end.y) {
            //         return true;
            //     }
            // }
            return false;
        }
        else {      //piece to kill
            if (pieceToKill->getColour() == colour) {   //kill same colour
                return false;   
            } else {
                // for (int i = 0; i < len; i++) {
                //     if (validMoves[i].x == end.x && validMoves[i].y == end.y) {
                //         return true;
                //     }
                // }
                return false;
            }
        }
    } else {
        return false; //not valid path
    }
}


bool Move::isValidPath() {
    Piece *p = board->getSquare(start.x, start.y).getPiece();
    if (p->getType() == "knight") { //knight can jump over
        return true;
    }
    if (start.x > end.x && start.y == end.y) { //path N
        for (int i = start.x - 1; i > end.x; i--) {
            Square s = board->getSquare(i, start.y);
            if (s.getPiece()) {
                return false;
            }
        }
        return true;
    }
    else if (start.y < end.y && start.x == end.x) { //path E
        for (int i = start.y + 1; i < end.y; i++) {
            Square s = board->getSquare(start.x, i);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.x < end.x && start.y == end.y) { //path S
        for (int i = start.x + 1; i < end.x; i++) {
            Square s = board->getSquare(i, start.y);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.y > end.y && start.x == end.x) { //path W
        for (int i = start.y - 1; i > end.y; i--) {
            Square s = board->getSquare(start.x, i);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.x > end.x && start.y > end.y) { //path NE
        for (int i = start.x - 1, j = start.y - 1; i > end.x && j > end.y; i--, j--) {
            Square s = board->getSquare(i, j);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.x < end.x && start.y < end.y) { //path SE
        for (int i = start.x + 1, j = start.y + 1; i < end.x && j < end.y; i++, j++) {
            Square s = board->getSquare(i, j);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.x < end.x && start.y > end.y) { //path SW
        for (int i = start.x + 1, j = start.y - 1; i < end.x && j > end.y; i++, j--) {
            Square s = board->getSquare(i, j);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    else if (start.x > end.x && start.y < end.y) { //path NW
        for (int i = start.x - 1, j = start.y + 1; i > end.x && j < end.y; i--, j++) {
            Square s = board->getSquare(i, j);
            if (s.getPiece()) {
                return false;
            }
        }
    }
    return true;
}

string Move::getMoveType() {
    return "normalMove";
}

bool Move::isEnpassant() {
    return true;
}

bool Move::isNormalKill() {
    Piece *pieceToKill = board->getSquare(end.x, end.y).getPiece();
    if (pieceToKill && pieceToKill->getColour() != colour) {
        return true;
    }
    return false;
}

