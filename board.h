#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "square.h"

class Board {
public:
 std::vector<std::vector<Square>> theBoard; // make the board of all 64 squares     

public:
 Board();
};

#endif
