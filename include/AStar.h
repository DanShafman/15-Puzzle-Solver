#include <iostream>
#include "Board.h"

// This class defines an object that will perform operations on an input Board
// to try to get it in the form of the goal Board.
class AStar {

public:
    AStar(const Board& start, const Board& goal);

    // Calulate the Manhattan distance of a tile on some Board from the goal
    // Board's corresponding tile. In other words, the distance of a tile from 
    // its goal position with only vertical and horizontal steps possible.
    int manhattanDistance(const Board& compBoard, int tile);

    // Calulate the sum of the Manhattan distance of each tile of some Board 
    // from the goal Board's corresponding tiles.
    int totalManhattanDistance(const Board& compBoard);

    // Solve the 15-block puzzle using A* algorithm and generate a sequence of
    // moves (L, R, U, or D) that will be returned as a vector of chars.
    std::vector<char> solveSequence();

private:
    Board currBoard;
    const Board goalBoard;

};