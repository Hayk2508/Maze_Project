#pragma once
#include "labyrinth.h"

class Treeocalypse:public Labyrinth {
public:
    Treeocalypse(){
        distances.resize(mazeHeight,std::vector<int>(mazeWidth,0));
    }
    void growth();
    void planting();
    void setDistancesFromPlayer(int x, int y,std::vector<std::vector<char>>& grid);
private:
    std::vector<std::vector<int>> distances;
};