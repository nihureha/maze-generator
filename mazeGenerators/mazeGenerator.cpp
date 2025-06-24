#include <iostream>
#include "mazeGenerator.h"

mazeGenerator::mazeGenerator(maze* newMaze) : m(newMaze) {}

void mazeGenerator::generate() {
    std::cout << "Don't call the generate() function on the maze generator class directly." << std::endl;
    return;
}

void mazeGenerator::connect(node* n1, node* n2) {
    int dx = n1->x - n2->x;
    int dy = n1->y - n2->y;

    int dxAbs = std::abs(dx);
    int dyAbs = std::abs(dy);

    if (dxAbs > 1 || dyAbs > 1 || (dxAbs == 1 && dyAbs == 1)) {
        std::cout << "Can't connect nodes from that far away" << std::endl;
        return;
    }

    if (n1->x == n2->x && n1->y == n2->y) {
        std::cout << "Can't connect 2 points together if they are the same point." << std::endl;
        return;
    }
    
    if (dx != 0) {
        if (dx > 0) {
            n1->west = n2;
            n1->adjacentNodes[3] = n2;
            n2->east = n1;
            n2->adjacentNodes[1] = n1;
        }
        else {
            n1->east = n2;
            n1->adjacentNodes[1] = n2;
            n2->west = n1;
            n2->adjacentNodes[3] = n1;
        }
    }
    if (dy != 0) {
        if (dy > 0) {
            n1->south = n2;
            n1->adjacentNodes[2] = n2;
            n2->north = n1;
            n2->adjacentNodes[0] = n1;
        }
        else {
            n1->north = n2;
            n1->adjacentNodes[0] = n2;
            n2->south = n1;
            n2->adjacentNodes[2] = n1;
        }
    }
}

node* mazeGenerator::findNewNode(node* n) {
    std::cout << "Don't call the findNewNode(node) function on the maze generator class directly." << std::endl;
    return n;
}

node* mazeGenerator::chooseRandomStartNode() {
    return &m->mazeMap[rand() % m->width][rand() % m->height];
}