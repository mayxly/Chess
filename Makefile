CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD -Werror=vla
EXEC = watopoly
OBJECTS = game.o main.o display.o player.o human.o board.o square.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

