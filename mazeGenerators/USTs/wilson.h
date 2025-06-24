#pragma once

#include "../mazeGenerator.h"
#include <stack>

class wilson : public mazeGenerator {
    public:
        wilson(maze*);
        void generate() override;
        void generate(bool);
        std::stack<node*> pending;
        std::unordered_set<node*> incomplete;
    protected:
        node* findNewNode(node*) override;
    private:
        void deleteVisitedCells(node*);
        void completeVisitedCells();
        void disconnect(node*, node*);
};
// Uniform spanning tree