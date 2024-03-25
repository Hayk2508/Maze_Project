#pragma once
#include "labyrinth.h"
#include "tree.h"
#include "humanplayer.h"

class Treeocalypse:public Labyrinth {
public:
    Treeocalypse();
    void planting();
    void setDistancesFromPlayer(humanPlayer& p);
    void findEmptyCells();
private:
    bool isWinnable();
    std::vector<std::vector<int>> distances;
    std::vector<Tree> plantedTrees;
    std::vector<std::pair<int,int>> emptyCells;
};