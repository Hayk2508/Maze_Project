#pragma once
#include "game.h"
#include "labyrinth.h"

class Player{
public:
     virtual bool move(std::vector<std::vector<char>>& mmaze) = 0;
};
