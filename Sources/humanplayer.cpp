#include "../Includes/humanplayer.h"
#include <windows.h>
#include "../Includes/labyrinth.h"
#include "../Includes/treeocalypse.h"

int humanPlayer::getX() const {
    return pX;
}

int humanPlayer::getY() const {
    return pY;
}

bool humanPlayer::move(std::vector<std::vector<char>> &Maze, int &axes) {
    bool madeMove = false;

    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (Labyrinth::isValidCell(pX - 1, pY )) {
            if (Maze[pX - 1][pY ] == '.') {
                Maze[pX][pY] = '.';
                madeMove = true;
                --pX;

                Treeocalypse::setEmptyCell(pX, pY);
                Treeocalypse::removeEmptyCell(pX, pY);

            } else if (Maze[pX - 1][pY ] == '#' && axes > 0) {
                Maze[pX][pY] = '.';
                madeMove = true;
                --pX;
                axes--;
            }
        }

    } else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (Labyrinth::isValidCell(pX + 1, pY )) {
            if (Maze[pX + 1][pY ] == '.') {
                Maze[pX][pY] = '.';
                madeMove = true;
                ++pX;

                Treeocalypse::setEmptyCell(pX, pY);
                Treeocalypse::removeEmptyCell(pX, pY);

            } else if (Maze[pX + 1][pY ] == '#' && axes > 0) {
                Maze[pX][pY] = '.';
                madeMove = true;
                ++pX;
                axes--;
            }
        }

    } else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (Labyrinth::isValidCell(pX, pY - 1)) {
            if (Maze[pX][pY - 1] == '.') {
                Maze[pX][pY] = '.';
                madeMove = true;
                --pY;

                Treeocalypse::setEmptyCell(pX, pY);
                Treeocalypse::removeEmptyCell(pX, pY);

            } else if (Maze[pX][pY - 1] == '#' && axes > 0) {
                Maze[pX][pY] = '.';
                madeMove = true;
                --pY;
                axes--;
            }
        }
    } else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (Labyrinth::isValidCell(pX, pY + 1)) {
            if (Maze[pX][pY + 1] == '.') {
                Maze[pX][pY] = '.';
                madeMove = true;
                ++pY;

                Treeocalypse::setEmptyCell(pX, pY);
                Treeocalypse::removeEmptyCell(pX, pY);

            } else if (Maze[pX][pY + 1] == '#' && axes > 0) {
                Maze[pX][pY] = '.';
                madeMove = true;
                ++pY;
                axes--;
            }
        }
    }

    if (madeMove) {
        Maze[pX][pY] = '@';
        return true;
    }
    return false;
}

void humanPlayer::setNickname(std::string &nickname) {
    this->nickname = nickname;
}

std::string humanPlayer::getNickname() const {
    return nickname;
}

void humanPlayer::setX(int x) {
    pX = x;
}

void humanPlayer::setY(int y) {
    pY = y;
}