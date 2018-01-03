GPP=g++
CXXFLAGS=  -fshow-column -fno-diagnostics-show-caret  -Wall -O2   -std=c++14
LDFLAGS=  -s -lsfml-system -lsfml-window -lsfml-graphics  
OBJS=Release/Character.o Release/sprite_jump.o Release/Global.o 

all: Release Release/sprite_jump.bin

clean:
	rm -rf ${OBJS} Release/sprite_jump.bin

Release/sprite_jump.bin: ${OBJS}
	${GPP} ${OBJS} ${LDFLAGS} -o $@

Release:
	mkdir Release

Release/Character.o: Character.cpp Character.hpp Global.hpp
	${GPP} ${CXXFLAGS} -c Character.cpp -o $@

Release/sprite_jump.o: sprite_jump.cpp Character.hpp Global.hpp
	${GPP} ${CXXFLAGS} -c sprite_jump.cpp -o $@

Release/Global.o: Global.cpp Global.hpp
	${GPP} ${CXXFLAGS} -c Global.cpp -o $@

