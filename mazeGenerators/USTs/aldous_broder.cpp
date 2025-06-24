#include <iostream>
#include "aldous_broder.h"

aldous_broder::aldous_broder(maze* newMaze) : mazeGenerator(newMaze) {}


void aldous_broder::generate() {
    generate(false);
}

void aldous_broder::generate(bool hybrid) { // is the hybrid algorithm being run?
    if (hybrid) {
        generate(m->size / 3);
    }
    else {
        generate(m->size);
        //m->printMaze(*this);
    }
}

void aldous_broder::generate(int squaresToComplete) {
    node* currentNode = &m->mazeMap[m->width - 1][m->height - 1];
    completed.insert(currentNode);
    node* nextNode = findNewNode(currentNode);
    //m->printMaze(currentNode, *this);
    while (completed.size() < squaresToComplete) {
        if (completed.count(nextNode) == 0) {
            completed.insert(nextNode);
            connect(currentNode, nextNode);
        }
        currentNode = nextNode;
        nextNode = findNewNode(currentNode);
        //m->printMaze(currentNode, *this);
    }
}

node* aldous_broder::findNewNode(node* n) {
    while (true) {
        switch (rand() % 4) {
            case 0: // north
                if (n->y == m->height - 1) continue;
                return &m->mazeMap[n->x][n->y + 1];
            case 1: // east
                if (n->x == m->width - 1) continue;
                return &m->mazeMap[n->x + 1][n->y];
            case 2: // south
                if (n->y == 0) continue;
                return &m->mazeMap[n->x][n->y - 1];
            case 3: // west
                if (n->x == 0) continue;
                return &m->mazeMap[n->x - 1][n->y];
        }
    }
    return nullptr;
}