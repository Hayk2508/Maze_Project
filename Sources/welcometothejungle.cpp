#include "../Includes/welcometothejungle.h"
#include <queue>
#include <random>
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <windows.h>
#include <algorithm>
#include <queue>
#include <iomanip>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

void WelcomeToTheJungle::make_unsolvable(humanPlayer& p) {
    for(auto exit: exits) {
        findWinnablePath({exit.first, exit.second}, p);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(2, 3);

        int numberOfTrees = distribution(gen);

        std::uniform_int_distribution<int> distribution1(0, winnablePath.size() - 1);
        while (numberOfTrees-- > 0) {
            int tree = distribution1(gen);
            this->maze[winnablePath[tree].first][winnablePath[tree].second] = '#';
        }
    }
}

int WelcomeToTheJungle::getAxes(){
    return this->axes;
}


void WelcomeToTheJungle::findWinnablePath(std::pair<int, int> exit, humanPlayer &p) {

    if(!winnablePath.empty())
        winnablePath.clear();

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> distances(mazeWidth, std::vector<int>(mazeHeight, 0));
    std::vector<std::vector<char>> visited(mazeWidth, std::vector<char>(mazeHeight, '0'));
    q.emplace(p.getX(), p.getY());

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (isValidCell(nx, ny) && this->maze[nx][ny] == '.' && visited[nx][ny]!='1') {
                q.emplace(nx, ny);
                distances[nx][ny] = distances[row][col] + 1;
                visited[nx][ny] = '1';
            }
        }
    }
    winnablePath.emplace_back(exit.first,exit.second);

    std::pair<int,int> curr = {exit.first,exit.second};

    while(curr.first!=p.getX() && curr.second!=p.getY()){
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if(isValidCell(nx,ny)  && distances[nx][ny] == distances[curr.first][curr.second] - 1){
                winnablePath.emplace_back(nx,ny);
                curr.first = nx;
                curr.second = ny;
            }
        }
    }


}
