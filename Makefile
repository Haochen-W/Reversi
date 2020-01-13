CXX = g++
CXXFLAGS = -std=c++14 -I/opt/X11/include -Wall -MMD -Werror=vla
EXEC = reversi
OBJECTS = main.o cell.o grid.o textdisplay.o graphicsdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@ -L/opt/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
