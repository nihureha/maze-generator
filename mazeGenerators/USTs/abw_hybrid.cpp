#include <iostream>
#include "abw_hybrid.h"

abw_hybrid::abw_hybrid(maze* newMaze) : mazeGenerator(newMaze) {}

void abw_hybrid::generate() { // aldous-broder/wilson's hybrid
    aldous_broder ab = aldous_broder(m);

    ab.generate(true);

    wilson w = wilson(m);

    for (node* completedNode : ab.completed) {
        w.completed.insert(completedNode);
        w.incomplete.erase(completedNode);
    }

    w.generate(true);
}