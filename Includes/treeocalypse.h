#pragma once
#include "labyrinth.h"
#include "tree.h"

class Treeocalypse:public Labyrinth {
public:
    void planting(std::vector<std::vector<int>>& distances);
    void setDistancesFromPlayer(humanPlayer& p,std::vector<std::vector<int>>& distances);
    void findEmptyCells();
    static void setEmptyCell(int x, int y);
    static void removeEmptyCell(int x,int y);
    bool isWinnable(std::vector<std::vector<int>>& distances);
private:
    std::vector<Tree> plantedTrees;
    static std::vector<std::pair<int,int>> emptyCells;
};