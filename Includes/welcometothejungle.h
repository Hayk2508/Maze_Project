#pragma once
#include "labyrinth.h"

class WelcomeToTheJungle:public Labyrinth{
public:
    void make_unsolvable(humanPlayer& p);
    int& getAxes();

    bool isWinnable(std::vector<std::vector<int>> &distances);
    void setDistancesFromPlayer(humanPlayer& p,std::vector<std::vector<int>>& distances);

private:
   void findWinnablePath(std::pair<int, int> s, humanPlayer & p );
    std::vector<std::pair<int,int>> winnablePath;
    int axes = 3;
};