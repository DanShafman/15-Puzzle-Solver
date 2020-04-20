#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <utility>

// This class defines an object represting a 15-puzzle board.
class Board {

public:
    // Takes an input 4x4 int array and copies it into tiles.
    Board(int inputTiles[4][4]);

    // Functions to shift the the tile in a particular direction, e.g. if the
    // blank space has a tile to its left, the shiftRight function will shift
    // that tile into the free space. Returns false if the operation is not
    // possible, true othrwise.
    bool shiftLeft();
    bool shiftRight();
    bool shiftUp();
    bool shiftDown();

    // Returns the location of a particular tile in the form of (x, y). Returns
    // (-1, -1) if an invalid tile is queried.
    std::pair<int, int> tileLocation(int tile) const;

    // Indexing operator returns the row specified by index, in an int array.
    const int* operator [] (int index) const;

    // Comarison operators for two Boards. Equality true if the nummbers at each
    // position are the same.
    bool operator == (const Board& rhs) const;
    bool operator != (const Board& rhs) const;

    // Output operator as defined for Board class. Prints the board in 4x4 
    // formation.
    friend std::ostream& operator << (std::ostream& out, const Board& board);

private:
    // The board itself is represented by a 4x4 integer array. The x and y 
    // positions of the blank space are stored in blankX and blankY. Note:
    // x will refer to the vertical position of a tile, and y to the
    // horizontal position.
    int tiles[4][4];
    int blankX, blankY;

};

#endif