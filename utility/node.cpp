#include "node.h"
#include <iostream>

node::node() : x(-1), y(-1), 
north(nullptr), east(nullptr), south(nullptr), west(nullptr), 
gCost(0), hCost(0), fCost(0), 
adjacentNodes({nullptr, nullptr, nullptr, nullptr}), 
prevNode(nullptr)
{}

node::node(int x, int y) : x(x), y(y), 
north(nullptr), east(nullptr), south(nullptr), west(nullptr), 
gCost(0), hCost(0), fCost(0), 
adjacentNodes({nullptr, nullptr, nullptr, nullptr}), 
prevNode(nullptr)
{}

node::node(int x, int y, node* n, node* e, node* s, node* w) : x(x), y(y), 
north(n), east(e), south(s), west(w), 
gCost(0), hCost(0), fCost(0), 
adjacentNodes({n, e, s, w}), 
prevNode(nullptr)
{}

bool node::operator==(const node& other) const {
    return (this->x == other.x) && (this->y == other.y);
}

bool node::operator!=(const node& other) const {
    return !(*this == other);
}

std::string node::toString() {
    return "node: (x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")";
}