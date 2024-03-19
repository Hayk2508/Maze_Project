#pragma once
#include "labyrinth.h"

class Treeocalypse:public Labyrinth {
public:
    void planting();
    void findWinnablePath(int x, int y);
};