#include <iostream>
#include <vector>
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
    // moves (L, R, U, or D). It will also generate a sequence of integers that
    // represent the cost of visiting each expanded node, as determined by the
    // evaluation function f(n) = cost to node + heuristic. Finally, the number
    // of nodes in the full tree visited by the solver is determined.
    
    // This data will be returned as a tuple of: vector of chars (move sequence), 
    // vector of ints (cost sequence), and an int (number of nodes in tree).
    void solveSequence();

    // Checks if the given Board configuration has already been previously 
    // expanded.
    bool isAlreadyExpanded(const Board& compBoard) const;

    // Getters for resulting A* values.
    const std::vector<char> getStepSequence() const;
    const std::vector<int> getCostSequence() const;
    const int getNumNodesVisited() const;

private:
    Board currBoard;
    const Board goalBoard;

    // Graph Search does not allow for repeated states, so this will keep track
    // of all the expanded states.
    std::vector<Board> alreadyExpanded;

    std::vector<char> stepSequence;
    std::vector<int> costSequence;
    int numNodesVisited;
};