#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
#include "info.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

class TextDisplay;
template <typename InfoType, typename StateType> class Observer;
class InvalidMove{};

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer<Info, State> *ob = nullptr;  // Another observer (intent:  graphics)
  // Add private members, if necessary.

 public:
  ~Grid();
  
  void setObserver(Observer<Info, State> *ob);
  bool isFull() const;  // Is the game over, i.e., is the grid full?
  Colour whoWon() const; // Who has more pieces when the board is full?
  void init(size_t n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void setPiece(size_t r, size_t c, Colour colour);  // Plays piece at row r, col c.
  void toggle(size_t r, size_t c);  // Flips piece at row r, col c.

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
