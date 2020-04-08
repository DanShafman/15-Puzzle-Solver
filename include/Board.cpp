#include "Board.h"

Board::Board(int inputTiles[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tiles[i][j] = inputTiles[i][j];
        }
    }
}

std::ostream& operator << (std::ostream& out, const Board& board) {

}