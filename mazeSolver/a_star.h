#pragma once

#include "../utility/maze.h"
#include "../utility/node.h"
#include <queue>
#include <unordered_set>

class a_star {
    private:
        maze* m;
        void setScores(node*);
    public:
        a_star(maze*);
        a_star(maze*, int, int, int, int);
        void solve();
        node* startPoint;
        node* endPoint;
        void probeSurroundingNodes(node*);
        struct CompareNodePointers {
            bool operator()(const node* a, const node* b) const {
                if (a->fCost != b->fCost) return a->fCost > b->fCost; // move node* b up the heap if b's fCost is less than a's fCost

                return a->hCost > b->hCost;
            }
        };
        std::unordered_set<node*> finished;
        std::unordered_set<node*> pendingUnorderedSet; // used for debugging only
        std::priority_queue<node*, std::vector<node*>, CompareNodePointers> pendingNodes; // uses comparator of CompareNodePointers defined above
        std::unordered_set<node*> solution;
};