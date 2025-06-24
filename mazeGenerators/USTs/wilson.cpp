#include <iostream>
#include "wilson.h"

wilson::wilson(maze* newMaze) : mazeGenerator(newMaze) {
    
    for (int i = 0; i < newMaze->width; i++) {
        for (int j = 0; j < newMaze->height; j++) {
            incomplete.insert(&newMaze->mazeMap[i][j]);
        }
    }
    
}

void wilson::generate() {
    generate(false);
}

void wilson::generate(bool hybrid) {
    if (!hybrid) { // if not using the hybrid function, add a random node to be the completed node
        node* newNode = &m->mazeMap[rand() % m->width][rand() % m->height];
        completed.insert(newNode);
        incomplete.erase(newNode);
    }
    
    node* currentNode = &m->mazeMap[rand() % m->width][rand() % m->height];
    
    while (completed.count(currentNode) == 1) {
        currentNode = &m->mazeMap[rand() % m->width][rand() % m->height];
    }

    visited.insert(currentNode);
    pending.push(currentNode);

    node* nextNode = findNewNode(currentNode);

    //m->printMaze(currentNode, *this);

    while (m->size > completed.size()) {
        if (completed.count(nextNode) == 1) { // next node is a complete node
            completeVisitedCells();
            connect(currentNode, nextNode);
            //m->printMaze(nextNode, *this);
            if (m->size == completed.size()) break;
            
            auto it = incomplete.begin();
            std::advance(it, (rand() % incomplete.size()));
            nextNode = *it;
            
            visited.insert(nextNode);
            pending.push(nextNode);
        }
        else if (visited.count(nextNode) == 1) { // next node is a visited node
            deleteVisitedCells(nextNode);
        }
        else { // nextNode is neither completed nor visited
            connect(currentNode, nextNode);
            visited.insert(nextNode);
            pending.push(nextNode);
        }
        currentNode = nextNode;
        nextNode = findNewNode(currentNode);
        //m->printMaze(currentNode, *this);
    }
    //m->printMaze(*this);
}

void wilson::deleteVisitedCells(node* n) {
    node* nodeToDelete = pending.top();
    node* before;
    while (nodeToDelete != n) {
        visited.erase(nodeToDelete);
        before = nodeToDelete;
        pending.pop();
        nodeToDelete = pending.top();
        disconnect(nodeToDelete, before);
    }
}

void wilson::completeVisitedCells() {
    auto it = visited.begin();
    node* pendingCompleteNode;
    while (it != visited.end()) {
        pendingCompleteNode = *it;
        
        completed.insert(pendingCompleteNode);
        incomplete.erase(pendingCompleteNode);
        it++;
        
        pending.pop();
    }
    visited.clear();
}

node* wilson::findNewNode(node* n) {
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

void wilson::disconnect(node* n1, node* n2) {
    int i;
    for (i = 0; i < n1->adjacentNodes.size(); i++) {
        if (n1->adjacentNodes[i] == n2) { // 0 = north, 1 = east, 2 = south, 3 = west
            n1->adjacentNodes[i] = nullptr;
            n2->adjacentNodes[(i + 2) % 4] = nullptr;
            break;
        }
    }
    switch (i) {
        case 0:
            n1->north = nullptr;
            n2->south = nullptr;
            break;
        case 1:
            n1->east = nullptr;
            n2->west = nullptr;
            break;
        case 2:
            n1->south = nullptr;
            n2->north = nullptr;
            break;
        case 3:
            n1->west = nullptr;
            n2->east = nullptr;
            break;
    }
}