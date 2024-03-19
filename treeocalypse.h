#pragma once
#include "labyrinth.h"

class Treeocalypse:public Labyrinth {
public:
    bool isGameOver() override;
    void planting();
   // std::vector<std::vector<char>> plantedTrees;

};