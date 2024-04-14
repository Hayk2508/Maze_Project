#pragma once
#include "player.h"
#include <conio.h>
#include <iostream>

class humanPlayer: public Player{
public:
    bool move(std::vector<std::vector<char>> & Maze, int& axes ) override;
    void setNickname(std::string& nickname);
    void setX(int x);
    void setY(int y);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    [[nodiscard]] std::string getNickname() const;
private:
    std::string nickname;
    int pX;

    int pY;
};