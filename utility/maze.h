#pragma once

#include "node.h"

class mazeGenerator;
class a_star;

class maze {
    public:
        int width;
        int height;
        int size;
        void printMaze();
        void printMaze(int, int, mazeGenerator);
        void printMaze(node*, mazeGenerator);
        void printMaze(mazeGenerator);
        void printMazeWithNums();
        void printNodeMaze();
        void printMazeWithSolution(a_star);
        void printMazeDuringSolve(a_star);
        node** mazeMap;
        maze(int, int);
        ~maze();
    private:
        void printNodeScore(node);
};