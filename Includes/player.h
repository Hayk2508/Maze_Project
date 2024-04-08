#pragma once
#include "game.h"
#include "labyrinth.h"
#include <vector>

class Player{
public:
     virtual bool move(std::vector<std::vector<char>>& maze) = 0;
};
