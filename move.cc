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
        vector <Position> validMoves = curPiece->getMoves(start);
        int len = validMoves.size();
        if (!pieceToKill) {    //no piece to kill, just move to square
            for (int i = 0; i < len; i++) {
                if (validMoves[i].x == end.x && validMoves[i].y == end.y) {
                    return true;
                }
            }
            return false;
        }
        else {      //piece to kill
            if (pieceToKill->getColour() == colour) {   //kill same colour
                return false;   
            } else {
                for (int i = 0; i < len; i++) {
                    if (validMoves[i].x == end.x && validMoves[i].y == end.y) {
                        return true;
                    }
                }
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
    if (isEnpassant()) return "enpassant";
    else if (isPromotepawn()) return "promotepawn";
    else if (isCastle()) return "castle";
    else if (isNormalKill()) return "normalkill";
    else return "normalmove";
}

bool Move::isEnpassant() {
    Position pawnPos = board->getRecentPawnPos();
    if (pawnPos.x == -1 && pawnPos.y == -1) { //pawn did not move on prev turn
        return false;
    }
    Piece *curPiece = board->getSquare(start.x, start.y).getPiece();
    if (curPiece->getType() != "pawn") { //curPiece not a pawn
        return false;
    }
    Square endSquare = board->getSquare(end.x, end.y);
    if (endSquare.getPiece() != nullptr) { //end square occupied
        return false;
    }
    Piece *pawnToKill; 
    if (colour == "white") {
        pawnToKill = board->getSquare(end.x+1, end.y).getPiece(); 
        if (!(pawnPos.x == end.x+1 && pawnPos.y == end.y)) { //not killing the correct pawn that just moved
            return false;
        }
    } else {
        pawnToKill = board->getSquare(end.x-1, end.y).getPiece();
        if (!(pawnPos.x == end.x-1 && pawnPos.y == end.y)) { //not killing the correct pawn that just moved
            return false;
        }
    }
    if (pawnToKill && pawnToKill->getType() == "pawn") {
        return true;
    }
    return false;
}



bool Move::isPromotepawn() {
    Piece *curPiece = board->getSquare(start.x, start.y).getPiece();
    if (curPiece && curPiece->getType() == "pawn") {
        if (curPiece->getColour() == "white" && end.x == 0) {
            return true;
        }
        else if (curPiece->getColour() == "black" && end.x == 7) {
            return true;
        }
    }
    return false;
}

bool Move::isCastle() { //king moves two squares towards rook
    Piece *curPiece = board->getSquare(start.x, start.y).getPiece();
    if (curPiece && curPiece->getType() == "king" && !curPiece->gethasMoved() && isValidPath()) {
        Piece *rook;
        if (start.y + 2 == end.y) { //king side castle
            if (curPiece->getColour() == "white") {
                rook = board->getSquare(7,7).getPiece();

            } else {
                rook = board->getSquare(0,7).getPiece();
            }
        } else {
            if (curPiece->getColour() == "white") {
                rook = board->getSquare(7,0).getPiece();
                if (board->getSquare(7, 1).getPiece() != nullptr) { //queen side castle check clear path
                    return false;
                }
            } else {
                rook = board->getSquare(0,0).getPiece();
                if (board->getSquare(0, 1).getPiece() != nullptr) { //queen side castle check clear path
                    return false;
                }
            }
        }
        if (rook && rook->getType() == "rook" && !rook->gethasMoved()) {
            return true;
        }
    }
    return false;
}

bool Move::isNormalKill() {
    Piece *pieceToKill = board->getSquare(end.x, end.y).getPiece();
    if (pieceToKill && pieceToKill->getColour() != colour) {
        return true;
    }
    return false;
}


