#pragma once

#include "../mazeGenerator.h"
#include "../../utility/maze.h"
#include "../../utility/node.h"

class aldous_broder : public mazeGenerator {
    public:
        aldous_broder(maze*);
        void generate() override;
        void generate(bool);
        void generate(int);
    protected:
        node* findNewNode(node*) override;
};
// Uniform spanning tree