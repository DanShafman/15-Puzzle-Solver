#include <string>
#include <iostream>

// This class defines an object represting a 15-puzzle board.
class Board {

public:
    // Takes an input 4x4 int array and copies it into tiles.
    Board(int inputTiles[4][4]);

    // Functions to shift the the tile in a particular direction, e.g. if the
    // blank space has a tile to its left, the shiftRight function will shift
    // that tile into the free space.
    void shiftLeft();
    void shiftRight();
    void shiftUp();
    void shiftDown();

    // Output operator as defined for Board class. Prints the board in 4x4 
    // formation.
    friend std::ostream& operator << (std::ostream& out, const Board& board);

private:
    // The board itself is represented by a 4x4 integer array.
    int tiles[4][4];

};