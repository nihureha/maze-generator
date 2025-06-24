#pragma once

#include "../utility/maze.h"
#include "../utility/node.h"
#include <unordered_set>


class mazeGenerator {
    public:
        mazeGenerator(maze*);
        virtual void generate();
        void connect(node*, node*);
        node* chooseRandomStartNode();
        std::unordered_set<node*> visited;
        std::unordered_set<node*> completed;
    protected:
        maze* m;
        virtual node* findNewNode(node*);
};