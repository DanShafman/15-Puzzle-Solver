#include "AStar.h"

#include <cmath>
#include <vector>

AStar::AStar(const Board& start, const Board& goal) : currBoard(start), goalBoard(goal) {
    solveSequence();
}

int AStar::manhattanDistance(const Board& compBoard, int tile) {
    // Save the location of the queried tile on the current and goal boards.
    std::pair<int, int> currTileLocation = compBoard.tileLocation(tile);
    std::pair<int, int> goalTileLocation = goalBoard.tileLocation(tile);

    // The Manhattan distance is the sum of the vertical and horizontal 
    // distances.
    int manhattanDist = abs(currTileLocation.first - goalTileLocation.first) + 
    abs(currTileLocation.second - goalTileLocation.second);

    return manhattanDist;
}

int AStar::totalManhattanDistance(const Board& compBoard) {
    int totalDist = 0;
    
    for (int tile = 1; tile < 16; tile++) {
        totalDist += manhattanDistance(compBoard, tile);
    }

    return totalDist;
}

bool AStar::isAlreadyExpanded(const Board& compBoard) const {
    for (Board b : alreadyExpanded) {
        if (compBoard == b) {
            return true;
        }
    }

    return false;
}

void AStar::solveSequence() {
    std::vector<char> stepSequence;
    std::vector<int> stepCosts;
    stepCosts.push_back(0);

    int totalCost = 0;
    int numNodesVisited = 0;

    // One step is one successful calculation of the next best step.
    while (currBoard != goalBoard) {
        // Two variables used for determining the best next step.
        char nextStep;
        int bestCost = -1;

        // Check left shift.
        if (currBoard.shiftLeft()) {
            int currTileVal = totalCost + totalManhattanDistance(currBoard);

            // If there is no current best value or the current node cost is 
            // better than the current best value...
            if ((bestCost == -1 || currTileVal <= bestCost) && 
            !isAlreadyExpanded(currBoard)) {
                bestCost = currTileVal;
                nextStep = 'L';
            }

            currBoard.shiftRight();
            numNodesVisited++;
        }

        // Check right shift.
        if (currBoard.shiftRight()) {
            int currTileVal = totalCost + totalManhattanDistance(currBoard);

            if ((bestCost == -1 || currTileVal <= bestCost) && 
            !isAlreadyExpanded(currBoard)) {
                bestCost = currTileVal;
                nextStep = 'R';
            }

            currBoard.shiftLeft();
            numNodesVisited++;
        }

        // Check up shift.
        if (currBoard.shiftUp()) {
            int currTileVal = totalCost + totalManhattanDistance(currBoard);

            if ((bestCost == -1 || currTileVal <= bestCost) && 
            !isAlreadyExpanded(currBoard)) {
                bestCost = currTileVal;
                nextStep = 'U';
            }

            currBoard.shiftDown();
            numNodesVisited++;
        }

        // Check down shift.
        if (currBoard.shiftDown()) {
            int currTileVal = totalCost + totalManhattanDistance(currBoard);

            if ((bestCost == -1 || currTileVal <= bestCost) && 
            !isAlreadyExpanded(currBoard)) {
                bestCost = currTileVal;
                nextStep = 'D';
            }

            currBoard.shiftUp();
            numNodesVisited++;
        }

        // Update all of the return data.
        totalCost += 1;
        stepSequence.push_back(nextStep);
        stepCosts.push_back(bestCost);

        // Apply the best operation.
        if (nextStep == 'L') {
            currBoard.shiftLeft();
        } else if (nextStep == 'R') {
            currBoard.shiftRight();
        } else if (nextStep == 'U') {
            currBoard.shiftUp();
        } else if (nextStep == 'D') {
            currBoard.shiftDown();
        }

        alreadyExpanded.push_back(currBoard);
    }

    this -> stepSequence = stepSequence;
    this -> costSequence = stepCosts;
    this -> numNodesVisited = numNodesVisited;
}

const std::vector<char> AStar::getStepSequence() const {
    return stepSequence;
}

const std::vector<int> AStar::getCostSequence() const {
    return costSequence;
}

const int AStar::getNumNodesVisited() const {
    return numNodesVisited;
}