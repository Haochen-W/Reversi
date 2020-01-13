# Reversi

## Introduction
Reversi is a strategy board game for two players, where players take turns placing a piece of their colour in a cell. The goal of Reversi is to have the most cells holding pieces of your colour at the end of the game. If a new piece _A_ would form a line segment with an existing piece _B_ of the same colour, such that all of the cells in between are occupied and of the opposite colour, those in-between pieces are ﬂipped to the same colour as _A_ and _B_.

## Design
This game employs the Observer Pattern in the design and has two available displays: text displays and graphic displays. Text display is available on the command line terminal. Graphic display is based on the use of X11, so the client should have X11 installed (Mac users will need to install XQuartz).  

## Instruction
The players need to give the commands in Linux Command Line. 

### Game Setup (For Linux and Mac Users in Command Line)
* Download and unzip the repository.
* Run the following command:
```
$ cd Reversi
$ make
```
* Execute the program:
```
$ ./reversi
```

### Several Commands for the Game
```
$ new n 
```
It creates a new n × n grid, where n ≥ 4 ∧ n ≡ 0 (mod 2). If there was already an active grid, that grid is destroyed and replaced with the new one. This command should be run at the beginning of the game. 

```
$ play r c 
```
Within a game, plays a piece at row _r_, column _c_ of the colour corresponding to the player who’s move it is. If the row and column entered correspond to a cell that already has a piece, or a position outside the grid, then the input is ignored and nothing is done. (The row/column number starts from zero). 


## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details.
