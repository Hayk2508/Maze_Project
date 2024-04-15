#pragma once

#include "humanPlayer.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <set>

class Labyrinth : public Game {
public:
    static bool isValidCell(int x, int y);


    static bool isBorderCell(int x, int y);
    void generateGrid(int x, int y);

    void play() override;

    Labyrinth();

protected:

    static void launchWelcomeToTheJungle();

    [[noreturn]]  static void launchTreeocalypse();

    void draw(int& axes , std::string game);


    void generateExits(int x, int y);

    std::set<std::pair<int, int>> exits;
    static constexpr int mazeWidth = 25;
    static constexpr int mazeHeight = 25;
    std::vector<std::vector<char>> maze;