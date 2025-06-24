#pragma once

#include "../mazeGenerator.h"
#include "../../utility/maze.h"
#include "../../utility/node.h"
#include "wilson.h"
#include "aldous_broder.h"

class abw_hybrid : public mazeGenerator {
    public:
        abw_hybrid(maze*);
        void generate() override;
};
// if less than 1/3rd of the maze is filled in, use Aldous-Broder
// if more than 1/3rd of the maze is filled in, use Wilson's