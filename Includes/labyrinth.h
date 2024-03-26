#pragma once

#include "game.h"
#include <vector>
#include <iostream>

class Labyrinth : public Game {
public:
    static bool isValidCell(int x, int y);

    void generateGrid(int x, int y);

    void play() override;

    Labyrinth();

protected:
    static void launchWelcomeToTheJungle();

    static bool isBorderCell(int x, int y);

    [[noreturn]]  void launchTreeocalypse();

    void draw() override;

    void generateExits(int x, int y);

    std::vector<std::pair<int, int>> exits;
    static constexpr int mazeWidth = 25;
    static constexpr int mazeHeight = 25;
    std::vector<std::vector<char>> maze;
    std::vector<std::pair<int, int>> winnablePath;
};