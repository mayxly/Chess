#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
 std::string colour;
 std::string name;

public:
 Player(std::string colour, std::string name);
 std::string getColour();
 virtual ~Player() = 0;
};

#endif
