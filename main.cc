#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Grid g;

    // Add code here
    bool blackturn = true;

    try {
        while (true) {
            cin >> cmd;
            if(cin.eof()) return 0;
            if (cmd == "new") {
                int n;
                cin >> n;
            if( n < 4 || n * n % 2 != 0) continue;
                // Add code here
                g.init(n);
                g.setPiece(n/2-1, n/2-1, Colour::Black);
                g.setPiece(n/2-1, n/2, Colour::White);
                g.setPiece(n/2, n/2-1, Colour::White);
                g.setPiece(n/2, n/2, Colour::Black);
                cout << g;
            } else if (cmd == "play") {
                int r = 0, c = 0;
                cin >> r >> c;
                // Add code here
                const int rownum = static_cast<size_t>(r);
                const int colnum = static_cast<size_t>(c);
                if (blackturn) {
                    try{g.setPiece(rownum, colnum, Colour::Black);}
                    catch (InvalidMove s){
                        continue;
                    }
                    cout << g;
                    blackturn = false;
                } else {
                    try{g.setPiece(rownum, colnum, Colour::White);}
                    catch (InvalidMove s){
                        continue;
                    }
                    cout << g;
                    blackturn = true;
                }
                if (g.isFull()) {
                    if (g.whoWon() == Colour::Black) {
                        cout << "Black Wins!" << endl;
                    } else if (g.whoWon() == Colour::White) {
                        cout << "White Wins!" << endl;
                    } else {
                        cout << "Tie!" << endl;
                    }
                    return 0;
                }
            }
        }
    }
  catch (ios::failure &) {}  // Any I/O failure quits
}
