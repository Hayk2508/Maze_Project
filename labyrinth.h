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

    [[noreturn]] void launchTreeocalypse();
    virtual bool isGameOver();
    void draw() override;
    void generateExits(int x, int y);

   static  constexpr int  mazeWidth = 20;
   static  constexpr int  mazeHeight = 20;
   std::vector<std::vector<char>> maze;
};