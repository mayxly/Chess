#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
 char colour;
 std::string name;

public:
 Player(char colour, std::string name);
};

#endif
