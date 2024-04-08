#pragma once

#include "humanPlayer.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <set>

class Labyrinth : public Game {
public:
    static bool isValidCell(int x, int y);

    void generateGrid(int x, int y);

    void play() override;

    Labyrinth();

protected:
    static void launchWelcomeToTheJungle();

    static bool isBorderCell(int x, int y);

    [[noreturn]]  static void launchTreeocalypse();

    void draw(int axes = 0 ) ;

    void generateExits(int x, int y);
    std::set<std::pair<int, int>> exits;
    static constexpr int mazeWidth = 27;
    static constexpr int mazeHeight = 27;
    std::vector<std::vector<char>> maze;
};