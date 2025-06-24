#pragma once

#include "../mazeGenerator.h"
#include "../../utility/maze.h"
#include "../../utility/node.h"

class growingTree : public mazeGenerator {
    public:
        growingTree(maze*);
        void generate() override;
    protected:
        node* findNewNode(node*) override;
};