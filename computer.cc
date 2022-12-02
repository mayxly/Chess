#include "computer.h"
using namespace std;

Computer::Computer(int level, std::string colour, std::string name) : Player{colour, name}, level{level} {}
