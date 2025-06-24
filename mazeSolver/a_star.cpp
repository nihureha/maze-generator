#include <iostream>
#include "a_star.h"

a_star::a_star(maze* m) : m(m), startPoint(&m->mazeMap[0][0]), endPoint(&m->mazeMap[m->width - 1][m->height - 1]) {
    startPoint->prevNode = nullptr;
}

a_star::a_star(maze* m, int n1X, int n1Y, int n2X, int n2Y) : m(m) {
    startPoint = &m->mazeMap[n1X][n1Y];
    endPoint = &m->mazeMap[n2X][n2Y];
    startPoint->prevNode = nullptr;
}

void a_star::solve() {
    pendingNodes.push(startPoint);
    node* currentNode = pendingNodes.top();
    while (currentNode != endPoint) {
        //m->printNodeMaze();
        //m->printMazeDuringSolve(*this);
        pendingUnorderedSet.erase(currentNode);
        pendingNodes.pop();
        probeSurroundingNodes(currentNode);
        finished.insert(currentNode);
        currentNode = pendingNodes.top();
    }
    node* nodeToAdd = endPoint;
    while (nodeToAdd != nullptr) {
        solution.insert(nodeToAdd);
        nodeToAdd = nodeToAdd->prevNode;
    }
}

void a_star::probeSurroundingNodes(node* n) {
    // sets all surrounding nodes to have their parent be node* n
    for (node* childNode : n->adjacentNodes) {
        if (childNode != nullptr && finished.count(childNode) == 0) {
            childNode->prevNode = n;
            setScores(childNode);
            pendingNodes.push(childNode);
            pendingUnorderedSet.insert(childNode);
        }
    }
}

void a_star::setScores(node* n) {
    n->gCost = (n->prevNode->gCost) + 1;
    n->hCost = std::abs(n->x - endPoint->x) + std::abs(n->y - endPoint->y);
    n->fCost = n->gCost + n->hCost;
}
