#include <iostream>
#include "maze.h"
#include "../mazeGenerators/mazeGenerator.h"
#include "../mazeSolver/a_star.h"

maze::maze(int mazeWidth, int mazeHeight) : width(mazeWidth), height(mazeHeight), size(mazeWidth * mazeHeight) {
    mazeMap = new node*[width];
    for (int i = 0; i < width; i++) {
        mazeMap[i] = new node[height];
        for (int j = 0; j < height; j++) {
            //mazeMap[i][j] = node(i, j);
            mazeMap[i][j].x = i;
            mazeMap[i][j].y = j;
        }
    }
}

maze::~maze() {
    for (int i = 0; i < width; i++) {
        delete[] this->mazeMap[i];
        this->mazeMap[i] = nullptr;
    }
    
    delete[] this->mazeMap;
    this->mazeMap = nullptr;
}

void maze::printMaze() {
    std::cout << std::endl << '+';
    for (int i = 0; i < maze::width; i++) {
        std::cout << "--+";
    }
    std::cout << std::endl;

    for (int i = maze::height - 1; i > -1; i--) {
        std::cout << "|";
        for (int j = 0; j < maze::width; j++) {
            std::cout << "  ";
            if (mazeMap[j][i].east == nullptr) std::cout << '|';
            else std::cout << ' '; 
        }
        std::cout << std::endl;
        std::cout << '+';
        for (int j = 0; j < maze::width; j++) {
            if (mazeMap[j][i].south == nullptr) std::cout << "--";
            else std::cout << "  ";
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}

void maze::printMaze(int x, int y, mazeGenerator mazeGen) {
    std::cout << std::endl << '+';
    for (int i = 0; i < maze::width; i++) {
        std::cout << "--+";
    }
    std::cout << std::endl;

    for (int i = maze::height - 1; i > -1; i--) {
        std::cout << "|";
        for (int j = 0; j < maze::width; j++) {
            if (j == x && i == y) std::cout << "OO";
            else if (mazeGen.completed.count(&mazeMap[j][i]) == 1) std::cout << "**";
            else if (mazeGen.visited.count(&mazeMap[j][i]) == 1) std::cout << "!!";
            else std::cout << "  ";
            if (mazeMap[j][i].east == nullptr) std::cout << '|';
            else std::cout << ' '; 
        }
        std::cout << std::endl;
        std::cout << '+';
        for (int j = 0; j < maze::width; j++) {
            if (mazeMap[j][i].south == nullptr) std::cout << "--";
            else std::cout << "  ";
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}

void maze::printMaze(mazeGenerator mazeGen) {
    printMaze(-1, -1, mazeGen);
}

void maze::printMaze(node* n, mazeGenerator mazeGen) {
    printMaze(n->x, n->y, mazeGen);
}

void maze::printNodeMaze() {
    node currNode;
    for (int i = height - 1; i > -1; i--) {
        for (int j = 0; j < width; j++) {
            std::cout << "g: ";
            if (mazeMap[j][i].gCost / 100 == 0) std::cout << 0;
            if (mazeMap[j][i].gCost / 10 == 0) std::cout << 0;
            std::cout << mazeMap[j][i].gCost << " | ";
        }
        std::cout << std::endl;
        for (int j = 0; j < width; j++) {
            std::cout << "h: ";
            if (mazeMap[j][i].hCost / 100 == 0) std::cout << 0;
            if (mazeMap[j][i].hCost / 10 == 0) std::cout << 0;
            std::cout << mazeMap[j][i].hCost << " | ";
        }
        std::cout << std::endl;
        for (int j = 0; j < width; j++) {
            std::cout << "f: ";
            if (mazeMap[j][i].fCost / 100 == 0) std::cout << 0;
            if (mazeMap[j][i].fCost / 10 == 0) std::cout << 0;
            std::cout << mazeMap[j][i].fCost << " | ";
        }
        std::cout << std::endl;
        for (int j = 0; j < width; j++) {
            std::cout << "---------";
        }
        std::cout << std::endl;
    }
}

void maze::printNodeScore(node n) {
    std::cout << "g: ";
    if (n.gCost / 100 == 0) std::cout << 0;
    if (n.gCost / 10 == 0) std::cout << 0;
    std::cout << n.gCost << std::endl;
    std::cout << "h: ";
    if (n.hCost / 100 == 0) std::cout << 0;
    if (n.hCost / 10 == 0) std::cout << 0;
    std::cout << n.hCost << std::endl;
    std::cout << "f: ";
    if (n.fCost / 100 == 0) std::cout << 0;
    if (n.fCost / 10 == 0) std::cout << 0;
    std::cout << n.fCost << std::endl;
}

void maze::printMazeWithNums() {
    std::cout << "   ";
    for (int i = 0; i < maze::width; i++) {
        std::cout << ' ';
        if (i < 10) std::cout << '0';
        std::cout << i;
    }
    std::cout << std::endl << "   " << '+';
    for (int i = 0; i < maze::width; i++) {
        std::cout << "--+";
    }
    std::cout << std::endl;

    for (int i = maze::height - 1; i > -1; i--) {
        if (i < 10) std::cout << '0';
        std::cout << i << " |";
        for (int j = 0; j < maze::width; j++) {
            std::cout << "  ";
            if (mazeMap[j][i].east == nullptr) std::cout << '|';
            else std::cout << ' ';
        }
        std::cout << std::endl << "   +";
        for (int j = 0; j < maze::width; j++) {
            if (mazeMap[j][i].south == nullptr) std::cout << "--";
            else std::cout << "  ";
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}

void maze::printMazeWithSolution(a_star solver) {
    std::cout << std::endl << '+';
    for (int i = 0; i < maze::width; i++) {
        std::cout << "--+";
    }
    std::cout << std::endl;

    for (int i = maze::height - 1; i > -1; i--) {
        std::cout << "|";
        for (int j = 0; j < maze::width; j++) {
            if (solver.startPoint == &mazeMap[j][i]) std::cout << "##";
            else if (solver.endPoint == &mazeMap[j][i]) std::cout << "@@";
            else if (solver.solution.count(&mazeMap[j][i]) == 1) std::cout << "**";
            else std::cout << "  ";
            if (mazeMap[j][i].east == nullptr) std::cout << '|';
            else std::cout << ' '; 
        }
        std::cout << std::endl;
        std::cout << '+';
        for (int j = 0; j < maze::width; j++) {
            if (mazeMap[j][i].south == nullptr) std::cout << "--";
            else std::cout << "  ";
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}

void maze::printMazeDuringSolve(a_star solver) {
     std::cout << std::endl << '+';
    for (int i = 0; i < maze::width; i++) {
        std::cout << "--+";
    }
    std::cout << std::endl;

    for (int i = maze::height - 1; i > -1; i--) {
        std::cout << "|";
        for (int j = 0; j < maze::width; j++) {
            if (solver.startPoint == &mazeMap[j][i]) std::cout << "@@";
            else if (solver.endPoint == &mazeMap[j][i]) std::cout << "##";
            else if (solver.finished.count(&mazeMap[j][i]) == 1) std::cout << "!!";
            else if (solver.pendingUnorderedSet.count(&mazeMap[j][i]) == 1) std::cout << "??";
            else std::cout << "  ";
            if (mazeMap[j][i].east == nullptr) std::cout << '|';
            else std::cout << ' '; 
        }
        std::cout << std::endl;
        std::cout << '+';
        for (int j = 0; j < maze::width; j++) {
            if (mazeMap[j][i].south == nullptr) std::cout << "--";
            else std::cout << "  ";
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}