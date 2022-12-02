#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
class Computer : public Player {
public:
    int level;
public:
    Computer(int level, std::string colour, std::string name);
};

#endif
