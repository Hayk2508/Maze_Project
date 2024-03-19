#pragma once
#include "game.h"
#include <vector>
#include <iostream>

class Labyrinth:public Game{
public:
    static bool isValidCell(int x,int y);
    void generateGrid(int x,int y);
    void play() override;
    Labyrinth();
protected:
    void launchWelcomeToTheJungle();
    void cut(int x,int y);
    bool isBorderCell(int x, int y);
    [[noreturn]] void launchTreeocalypse();
    void draw() override;
    void generateExits(int x, int y);

    int exitCount{};
   static  constexpr int  mazeWidth = 20;
   static  constexpr int  mazeHeight = 20;
   std::vector<std::vector<char>> maze;
   std::vector<std::pair<int,int>> winnablePath;
};