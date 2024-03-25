#include "../Includes/humanplayer.h"
#include <windows.h>
#include "../Includes/labyrinth.h"

int humanPlayer::getX() const{
    return pX;
}
int humanPlayer::getY() const{
    return pY;
}

void humanPlayer::setNickname(std::string& nickname) {
    this->nickname = nickname;
}

bool humanPlayer::move(std::vector<std::vector<char>>& tMaze) {
    bool tmp = false;
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (Labyrinth::isValidCell(pX - 1, pY) && tMaze[pX - 1][pY] == '.') {
            tMaze[pX][pY] = '.';
            --pX;
            tmp = true;
        }

    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (Labyrinth::isValidCell(pX + 1, pY) && tMaze[pX + 1][pY] == '.') {
            tMaze[pX][pY] = '.';
            ++pX;
            tmp = true;
        }


    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (Labyrinth::isValidCell(pX, pY - 1) && tMaze[pX][pY - 1] == '.') {
            tMaze[pX][pY] = '.';
            --pY;
            tmp = true;
        }

    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (Labyrinth::isValidCell(pX, pY + 1) && tMaze[pX][pY + 1] == '.') {
            tMaze[pX][pY] = '.';
            ++pY;
            tmp = true;
        }

}
    if(tmp){
        tMaze[pX][pY] = '@';
        return true;
    }
    return false;
}

std::string humanPlayer::getNickname() const{
    return nickname;
}
void humanPlayer::setX(int x) {
    pX = x;
}
void humanPlayer::setY(int y) {
    pY = y;
}