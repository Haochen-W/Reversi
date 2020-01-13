#include "cell.h"
#include <iostream>

Cell::Cell(size_t r, size_t c): r{r}, c{c} {}

void Cell::setPiece(Colour colour){
	this->colour = colour;
	State s{StateType::NewPiece, colour, Direction::NW};
	this->setState(s);
	this->notifyObservers();
}

void Cell::toggle() {
	if (colour == Colour::Black) {
		colour = Colour::White;
		return;
	} 
	if (colour == Colour::White) {
		colour = Colour::Black;
		return;
	} 
}

Info Cell::getInfo () const{
	Info temp {r, c, colour};
	return temp;
}

void Cell::notify(Subject<Info, State> &whoFrom){ 
	// Keep in mind: this is the cell being notified
	// unused cell, do nothing

	// empty cell
	if (colour == Colour::NoColour) return;

	// subject info
	const int fromr = static_cast<int>(whoFrom.getInfo().row);
	const int fromc = static_cast<int>(whoFrom.getInfo().col);
	Colour col = whoFrom.getState().colour;
	Direction dir;

	// observer info
	const int herer = static_cast<int>(this->getInfo().row);
	const int herec = static_cast<int>(this->getInfo().col);

	// set the correct direction
	if ((fromr == herer + 1) && (fromc == herec + 1)){
		dir = Direction::NW;
	}
	if ((fromr == herer + 1) && (fromc == herec)){
		dir = Direction::N;
	}
	if ((fromr == herer + 1) && (fromc == herec - 1)){
		dir = Direction::NE;
	}
	if ((fromr == herer) && (fromc == herec + 1)){
		dir = Direction::W;
	}
	if ((fromr == herer) && (fromc == herec - 1)){
		dir = Direction::E;
	}
	if ((fromr == herer - 1) && (fromc == herec + 1)){
		dir = Direction::SW;
	}
	if ((fromr == herer - 1) && (fromc == herec)){
		dir = Direction::S;
	}
	if ((fromr == herer - 1) && (fromc == herec - 1)){
		dir = Direction::SE;
	}

	State before = whoFrom.getState();

	// not from the same direction
	if (before.type != StateType::NewPiece && dir != before.direction) return;

	// replying 
	if (before.type == StateType::Reply) {
		// back to the newPiece
		if (this->colour == before.colour) return;
		// flip piece		
		this->toggle();
		State after = {StateType::Reply, col, dir};
		this->setState(after);
		this->notifyObservers();
		return;
	}

	// relay
	if (this->colour != col) {
		// go on
		State after = {StateType::Relay, col, dir};
		this->setState(after);
		this->notifyObservers();
		return;
	}

	// start reply, change direction
	if (this->colour == col) {
		if (dir == Direction::NW) {
			dir = Direction::SE;
		} else if (dir == Direction::N) {
			dir = Direction::S;
		} else if (dir == Direction::NE) {
			dir = Direction::SW;
		} else if (dir == Direction::W) {
			dir = Direction::E;
		} else if (dir == Direction::E) {
			dir = Direction::W;
		} else if (dir == Direction::SW) {
			dir = Direction::NE;
		} else if (dir == Direction::S) {
			dir = Direction::N;
		} else if (dir == Direction::SE) {
			dir = Direction::NW;
		}
		State after = {StateType::Reply, col, dir};
		this->setState(after);
		this->notifyObservers();
	}
}
