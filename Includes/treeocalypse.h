#pragma once
#include "labyrinth.h"

class Treeocalypse:public Labyrinth {
public:
    void growth();
    void planting();
    void findWinnablePath(int x, int y);
};