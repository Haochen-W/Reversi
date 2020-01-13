#include "textdisplay.h"

TextDisplay::TextDisplay(size_t n): gridSize{n} {
	std::vector<char> temp (n, '-');
	std::vector<std::vector<char>> temp2 (n, temp);
	theDisplay = temp2;
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
	Info c = whoNotified.getInfo();
	if (c.colour == Colour::Black) {
		theDisplay[c.row][c.col] = 'B';
	}
	if (c.colour == Colour::White) {
		theDisplay[c.row][c.col] = 'W';
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	const int n = static_cast<int>(td.gridSize);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			out << td.theDisplay[i][j];
		}
		out << std::endl;
	}

	return out;
}
