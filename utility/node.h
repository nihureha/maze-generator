#pragma once

#include <functional>

class node {
    public:
        int x;
        int y;
        node* north;
        node* east;
        node* south;
        node* west;
        std::array<node*, 4> adjacentNodes;
        /**
         * adjacentNodes[0] = north
         * adjacentNodes[1] = east
         * adjacentNodes[2] = south
         * adjacentNodes[3] = west;
         */
        node();
        node(int, int);
        node(int, int, node*, node*, node*, node*);
        bool operator==(const node&) const;
        bool operator!=(const node&) const;
        std::string toString();
        // a* alg node features
        int gCost;
        int hCost;
        int fCost;
        node* prevNode;
};
/*
namespace std {
    template<>
    struct greater<node> {
        bool operator()(const node& a, const node& b) const {
            if (a.fCost != b.fCost) return a.fCost > b.fCost;
            
            return a.hCost > b.hCost;
        }
    };
    template<>
    struct hash<node> {
        std::size_t operator()(const node& n) const {
            return n.x ^ (n.y << 1);
        }
    };
}
*/

