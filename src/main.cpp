#include "../include/Board.cpp"
#include "../include/AStar.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int startB[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 0}};
    int goalB[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 0}};

    Board s(startB);
    Board g(goalB);
    // cout << "Starting board:\n"<< s << endl;
    // cout << "Goal board:\n" << g << endl;

    // AStar a(s, g);

    // for (char c : a.solveSequence()) {
    //     cout << c << " ";
    // }
    // cout << endl;

    // Check that number of sysargs is correct.
    if (argc != 2) {
        cerr << "Please enter one parameter after the program: the name of the" 
        " file" << endl;
        exit(1);
    }

    // Open and verify input file.
    std::ifstream infile;
    infile.open(argv[1]);
    if (!infile) {
        cerr << "File not found" << endl;
        exit(1);
    }

    // Parse input file for the starting configuration and create the 
    // corresponding Board.
    string nextTile;
    int startConfig[4][4];

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            infile >> nextTile;
            startConfig[x][y] = std::stoi(nextTile);
        }
    }

    Board startBoard(startConfig);

    // Parse input file for the goal configuration and create the 
    // corresponding Board.
    int goalConfig[4][4];

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            infile >> nextTile;
            goalConfig[x][y] = std::stoi(nextTile);
        }
    }

    infile.close();
    Board goalBoard(goalConfig);

    // Generate AStar object with the start and end Boards; this will 
    // automatically generate the path to get to the goal from the start.
    AStar puzzleSolver(startBoard, goalBoard);


    vector<char> stepSequence = puzzleSolver.getStepSequence();
    vector<int> costSequence = puzzleSolver.getCostSequence();
    int numNodesVisited = puzzleSolver.getNumNodesVisited();
    
    // Write output to output file, called "output.txt."
    ofstream outfile;
    outfile.open("output.txt");

    // Starting configuration.
    outfile << startBoard << endl;
    // Goal configuration.
    outfile << goalBoard << endl;
    // Depth of goal node.
    outfile << stepSequence.size() << endl;
    // Number of nodes visited.
    outfile << numNodesVisited << endl;
    // Sequence of steps taken.
    for (char step : stepSequence) {
        outfile << step << " ";
    }
    outfile << endl;
    // Sequence of node evaluations.
    for (int cost : costSequence) {
        outfile << cost << " ";
    }
    outfile << endl;

    outfile.close();
}
