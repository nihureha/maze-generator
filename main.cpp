#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include "utility/node.h"
#include "utility/maze.h"
#include "mazeGenerators/mazeGenerator.h"
#include "mazeGenerators/MiscSTs/dfs.h"
#include "mazeGenerators/MSTs/prim.h"
#include "mazeGenerators/MSTs/growingTree.h"
#include "mazeSolver/a_star.h"
#include "mazeGenerators/USTs/wilson.h"
#include "mazeGenerators/USTs/aldous_broder.h"
#include "mazeGenerators/USTs/abw_hybrid.h"

int main() {

    srand(time(0));
    
    int width, height;

    std::cout << "Choose the dimensions of your maze:" << std::endl;

    std::cin >> width >> height;

    std::cout << "This is the width: " << width << "\nThis is the height: " << height << std::endl << "---------------------------------------------------------------------------------------------------" << std::endl;
    

    std::cout << "Depth First Search:" << std::endl;
    maze* m1 = new maze(width, height);

    dfs dfsGen = dfs(m1);
    
    dfsGen.generate();

    m1->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;
    
    a_star m1solver = a_star(m1);

    m1solver.solve();

    m1->printMazeWithSolution(m1solver);

    delete m1;
    m1 = nullptr;

    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Prim's:" << std::endl;
    maze* m2 = new maze(width, height);

    prim primGen = prim(m2);

    primGen.generate();

    m2->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;
    
    a_star m2solver = a_star(m2);

    m2solver.solve();

    m2->printMazeWithSolution(m2solver);
    
    delete m2;
    m2 = nullptr;

    
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Growing Tree:" << std::endl;
    maze* m3 = new maze(width, height);

    growingTree gt = growingTree(m3);

    gt.generate();

    m3->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;
    
    a_star m3solver = a_star(m3);

    m3solver.solve();

    m3->printMazeWithSolution(m3solver);

    delete m3;
    m3 = nullptr;

    
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Wilson's:" << std::endl;
    maze* m4 = new maze(width, height);

    wilson w = wilson(m4);

    w.generate();

    m4->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;

    a_star m4solver = a_star(m4);

    m4solver.solve();

    m4->printMazeWithSolution(m4solver);

    delete m4;
    m4 = nullptr;
    
    
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Aldous-Broder:" << std::endl;
    maze* m5 = new maze(width, height);

    aldous_broder ab = aldous_broder(m5);

    ab.generate();

    m5->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;

    a_star m5solver = a_star(m5);

    m5solver.solve();

    m5->printMazeWithSolution(m5solver);

    delete m5;
    m5 = nullptr;

    
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Aldous-Broder/Wilson's Hybrid:" << std::endl;
    maze* m6 = new maze(width, height);

    abw_hybrid abw = abw_hybrid(m6);

    abw.generate();

    m6->printMaze();

    std::cout << std::endl << "Solution:" << std::endl;

    a_star m6solver = a_star(m6);

    m6solver.solve();

    m6->printMazeWithSolution(m6solver);

    delete m6;
    m6 = nullptr;
    

    return 0;
}