#pragma once
#include "player.h"
#include <conio.h>
#include <iostream>

class humanPlayer: public Player{
public:
    bool  move(std::vector<std::vector<char>>& mmaze) override;
    void setNickname(std::string& nickname);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    std::string getNickname();

private:
    std::string nickname;
    int pX;
    int pY;
};