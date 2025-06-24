#include <iostream>
#include "prim.h"

prim::prim(maze* newMaze) : mazeGenerator(newMaze) {}

void prim::generate() {
    node* currentNode = chooseRandomStartNode();
    node* nextNode = findNewNode(currentNode);
    visited.insert(currentNode);

    while (completed.size() < m->size) {
        /*
        std::cout << "choosing a random spot" << std::endl;
        m.printMaze(currentNode, *this);
        std::cout << "-------------" << std::endl;
        */
        if (nextNode == nullptr) {
            completed.insert(currentNode);
            visited.erase(currentNode);
        }
        else {
            visited.insert(nextNode);
            connect(currentNode, nextNode);
        }
        /*
        std::cout << "Branching out to a new spot from the random spot" << std::endl;
        m.printMaze(currentNode, *this);
        if (completed.count(currentNode) == 1) {
            std::cout << "Can't branch out from an already completed node" << std::endl;
            m.printMaze(*this);
        }
        */
        

        //std::cout << "-------------" << std::endl;
        
        auto it = visited.begin();
        if (visited.size() != 0) {
            std::advance(it, rand() % visited.size());
            currentNode = *it;
        }
        nextNode = findNewNode(currentNode);
    }
}

node* prim::findNewNode(node* n) {
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