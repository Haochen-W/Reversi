#include "grid.h"

Grid::~Grid(){
	delete td;
	delete ob;
}

bool Grid::isFull() const {
	const int n = theGrid.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (theGrid[i][j].getInfo().colour == Colour::NoColour) {
				return false;
			}
		}
	} 
	return true;
}

Colour Grid::whoWon() const{
	int black = 0;
	int white = 0;
	const int n = theGrid.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (theGrid[i][j].getInfo().colour == Colour::Black) {
				black += 1;
			}
			if (theGrid[i][j].getInfo().colour == Colour::White) {
				white += 1;
			}
		}
	} 
	if (black > white) return Colour::Black;
	if (white > black) return Colour::White;
	return Colour::NoColour;
}

void Grid::toggle(size_t r, size_t c) {
	if ((theGrid[r][c]).getInfo().colour != Colour::NoColour){
		(theGrid[r][c]).toggle();
	}
}

void Grid::setObserver(Observer<Info, State> *ob){
	this->ob = ob;
}

void Grid::init(size_t n) {
	const int oldn = theGrid.size();
	const int newn = static_cast<int>(n);

	// delete the old
	for (int i = 0; i < oldn; i++) {
		theGrid[i].clear();
	}
	theGrid.clear();
	delete td;
	delete ob;
	// create the new one
	td = new TextDisplay(newn);
	ob = new GraphicsDisplay(newn);
	for (int i = 0; i < newn; i++) {
		std::vector<Cell> temp;
		for (int j = 0; j < newn; j++) {
			Cell temp2 {static_cast<size_t>(i), static_cast<size_t>(j)};
			temp.emplace_back(temp2);
		}
		theGrid.emplace_back(temp);
	}

}

void Grid::setPiece(size_t r, size_t c, Colour colour){
	const int rownum = static_cast<int>(r);
	const int colnum = static_cast<int>(c);
	const int gsize = theGrid.size();
	InvalidMove invalid;

	if (rownum < 0 || colnum < 0 || rownum >= gsize || colnum >= gsize){
		// out of range, do not set new piece
		throw invalid;
		return;
	}

	if (theGrid[r][c].getInfo().colour != Colour::NoColour) {
		// do not set new piece
		throw invalid;
		return;
	}
	// attach neighbours
	for (int i = rownum - 1; i < rownum + 2; i++){
		for (int j = colnum - 1; j < colnum + 2; j++) {
			if (i >= gsize || i < 0 || j < 0 || j >= gsize || 
				(i == rownum && j == colnum)) {
				continue;
			}
			theGrid[r][c].attach(&theGrid[i][j]);
		}
	}
	theGrid[r][c].attach(td);
	theGrid[r][c].attach(ob);
	// to notify neighbors
	theGrid[r][c].setPiece(colour);
}

std::ostream &operator<<(std::ostream &out, const Grid &g){
	out << *(g.td);
	return out; 
}
