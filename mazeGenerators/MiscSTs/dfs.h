#pragma once

#include "../mazeGenerator.h"
#include "../../utility/maze.h"
#include "../../utility/node.h"


class dfs : public mazeGenerator {
    public:
        dfs(maze*);
        void generate() override;
        void generate(node*);
    protected:
        node* findNewNode(node*) override;
};