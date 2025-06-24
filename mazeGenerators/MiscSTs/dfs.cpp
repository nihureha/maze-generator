#include <iostream>
#include "dfs.h"

dfs::dfs(maze* newMaze) : mazeGenerator(newMaze) {}

void dfs::generate() {
    node* startNode = mazeGenerator::chooseRandomStartNode();
    generate(startNode);
}

void dfs::generate(node* currentNode) {
    visited.insert(currentNode);

    node* nextNode = findNewNode(currentNode);

    while (nextNode != nullptr) {
        //m.printMaze(currentNode->x, currentNode->y, *this);
        connect(currentNode, nextNode);
        generate(nextNode);
        nextNode = findNewNode(currentNode);
    }
    //m.printMaze(currentNode->x, currentNode->y, *this);
    visited.erase(currentNode);
    completed.insert(currentNode);
    //m.printMaze(*this);
    return;
}

node* dfs::findNewNode(node* n) {
    node* newNode = nullptr;
    bool checkNorth = true, checkEast = true, checkSouth = true, checkWest = true;
    while (checkNorth || checkEast || checkSouth || checkWest) {
        switch(rand() % 4) {
            case 0:
                if (n->y == m->height - 1) {
                    checkNorth = false;
                    continue;
                }
                newNode = &m->mazeMap[n->x][n->y + 1];
                if (visited.count(newNode) == 1 || completed.count(newNode) == 1) {
                    checkNorth = false;
                    continue;
                }
                return newNode;
            case 1:
                if (n->x == m->width - 1) {
                    checkEast = false;
                    continue;
                }
                newNode = &m->mazeMap[n->x + 1][n->y];
                if (visited.count(newNode) == 1 || completed.count(newNode) == 1) {
                    checkEast = false;
                    continue;
                }
                return newNode;
            case 2:
                if (n->y == 0) {
                    checkSouth = false;
                    continue;
                }
                newNode = &m->mazeMap[n->x][n->y - 1];
                if (visited.count(newNode) == 1 || completed.count(newNode) == 1) {
                    checkSouth = false;
                    continue;
                }
                return newNode;
            case 3:
                if (n->x == 0) {
                    checkWest = false;
                    continue;
                }
                newNode = &m->mazeMap[n->x - 1][n->y];
                if (visited.count(newNode) == 1 || completed.count(newNode) == 1) {
                    checkWest = false;
                    continue;
                }
                return newNode;
        }
    }
    return nullptr;
}