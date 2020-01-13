#ifndef STATE_H
#define STATE_H

/* State types are:
    NewPiece -- I am a new piece.  I was just placed on the board.  I'm letting
                you know that I exist, in case you need to change colour.

    Relay -- I have a neighbour (or a neighbour's neighbour, etc.) who is a 
             new piece, not of my colour, and is a straight line away from me.
             I'm letting you know that that neighbour exists, and in which
             direction it is, in case you need to change colour.

    Reply -- I have a neighbour (or a neighbour's neighbour, etc.) who is a
             new piece, of my colour, and is a straight line away from me.  OR
             I am an in between piece, and am changing my colour now.
*/
enum class StateType { NewPiece, Relay, Reply };
enum class Colour { NoColour, Black, White };
enum class Direction { NW, N, NE, W, E, SW, S, SE };

struct State {
  StateType type;  // See above
  Colour colour;   // What colour was the new piece?  (NOT what is my colour)
  Direction direction;  // In which direction from me is the new piece?
};

#endif
