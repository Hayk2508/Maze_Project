#pragma once
#include "labyrinth.h"
#include "tree.h"
#include "humanplayer.h"

class Treeocalypse:public Labyrinth {
public:
    void planting(std::vector<std::vector<int>>& distances);
    void setDistancesFromPlayer(humanPlayer& p,std::vector<std::vector<int>>& distances);
    void findEmptyCells();
    static void setEmptyCell(int x, int y);
    static void removeEmptyCell(int x,int y);
private:
    bool isWinnable(std::vector<std::vector<int>>& distances);
    std::vector<Tree> plantedTrees;
    static std::vector<std::pair<int,int>> emptyCells;
};