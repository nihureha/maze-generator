#include <iostream>
#include "growingTree.h"
#include <random>

growingTree::growingTree(maze* newMaze) : mazeGenerator(newMaze) {}

void growingTree::generate() {
    node* currentNode = chooseRandomStartNode();
    node* nextNode = currentNode;
    visited.insert(currentNode);
    int numberedMode = 0;
    while (completed.size() < m->size) {
        if ((visited.size() != 0 && numberedMode == 4) || completed.count(currentNode) == 1) {
            /*
            if (nextNode != nullptr) {
                std::cout << "Traveling to an adjacent unvisited cell" << std::endl;
                m.printMaze(nextNode, *this);
            }
            else {
                std::cout << "Filled in this cell as completed" << std::endl;
                m.printMaze(*this);
            }
            std::cout << "Choosing a random cell..." << std::endl;
            */
            auto it = visited.begin();
            std::advance(it, rand() % visited.size());
            currentNode = *it;

            numberedMode = 0;
        }
        else {
            currentNode = nextNode;
            //std::cout << "Traveling to an adjacent unvisited cell" << std::endl;
        }
        nextNode = findNewNode(currentNode);

        //m.printMaze(currentNode, *this);
        if (nextNode == nullptr) {
            completed.insert(currentNode);
            visited.erase(currentNode);
            numberedMode = 0;
        }
        else {
            visited.insert(nextNode);
            connect(currentNode, nextNode);
        }
        if (numberedMode == 4) numberedMode = 0;
        numberedMode++;
    }
    //std::cout << "All cells marked as complete" << std::endl;
    //m.printMaze(*this);
}

node* growingTree::findNewNode(node* n) {
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