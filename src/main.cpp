#include "../include/Board.cpp"
#include "../include/AStar.cpp"

#include <iostream>

using namespace std;

int main() {
    int startBoard[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 0}};
    int goalBoard[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 0}};

    Board s(startBoard);
    Board g(goalBoard);
    cout << "Starting board:\n"<< s << endl;
    cout << "Goal board:\n" << g << endl;

    // s.shiftRight();
    // s.shiftDown();
    // s.shiftLeft();
    // s.shiftUp();
    // s.shiftRight();
    // s.shiftDown();
    // s.shiftLeft();
    // s.shiftUp();
    // s.shiftUp();
    // s.shiftRight();
    // s.shiftDown();
    // s.shiftLeft();

    // cout << s[1][1] << endl;
    AStar a(s, g);

    for (char c : a.solveSequence()) {
        cout << c << " ";
    }
    cout << endl;
}