#include "Board.h"

Board::Board(int inputTiles[4][4]) {
    // It is assumed that each of the 16 positions has been assigned a value
    // due to the constraints of the assignment. TODO: implement error handling
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            tiles[x][y] = inputTiles[x][y];

            // Store position of the blank space.
            if (inputTiles[x][y] == 0) {
                blankX = x; 
                blankY = y;
            }
        }
    }
}

bool Board::shiftLeft() {
    // Not possible if blank space is at the right.
    if (blankY == 3) {
        return false;
    }
    
    tiles[blankX][blankY] = tiles[blankX][blankY + 1];
    tiles[blankX][blankY + 1] = 0;
    blankY++;

    return true;
}

bool Board::shiftRight() {
    // Not possible if blank space is at the left.
    if (blankY == 0) {
        return false;
    }
    
    tiles[blankX][blankY] = tiles[blankX][blankY - 1];
    tiles[blankX][blankY - 1] = 0;
    blankY--;

    return true;
}

bool Board::shiftUp() {
    // Not possible if blank space is at the bottom.
    if (blankX == 3) {
        return false;
    }
    
    tiles[blankX][blankY] = tiles[blankX + 1][blankY];
    tiles[blankX + 1][blankY] = 0;
    blankX++;

    return true;
}

bool Board::shiftDown() {
    // Not possible if blank space is at the top.
    if (blankX == 0) {
        return false;
    }
    
    tiles[blankX][blankY] = tiles[blankX - 1][blankY];
    tiles[blankX - 1][blankY] = 0;
    blankX--;

    return true;
}

int* Board::operator [] (int index) {
    return tiles[index];
}   

bool Board::operator == (const Board& rhs) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {

            // Compare every position in the Board.
            if (tiles[x][y] != rhs.tiles[x][y]) {
                return false;
            }

        }
    }

    return true;
}

std::ostream& operator << (std::ostream& out, const Board& board) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            out << board.tiles[x][y] << " ";
        }
        out << std::endl;
    }

    return out;
}
