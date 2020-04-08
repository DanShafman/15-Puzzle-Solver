#include "../include/Board.cpp"
#include "../include/AStar.cpp"

#include <iostream>

using namespace std;

int main() {
    int testBoard[4][4] = {{1,2,3,4}, {5,6,0,7}, {8,9,10,11}, {12, 13, 14, 15}};

    Board b(testBoard);
    Board c(testBoard);
    cout << b << endl;
    cout << (b == c) << endl;

    b.shiftUp();
    // cout << b << endl;

    b.shiftUp();
    // cout << b << endl;

    b.shiftUp();
    // cout << b << endl;

    b.shiftUp();
    // cout << b << endl;

    // cout << b[3][1] << endl;

    cout << (b == c) << endl;
}