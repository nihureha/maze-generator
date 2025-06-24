#pragma once

#include <set>

#include "../mazeGenerator.h"
#include "../../utility/maze.h"
#include "../../utility/node.h"


class prim : public mazeGenerator {
    public:
        prim(maze*);
        void generate() override;
    protected:
        node* findNewNode(node*) override;
};