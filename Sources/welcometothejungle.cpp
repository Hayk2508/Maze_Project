#include "../Includes/welcometothejungle.h"
#include <queue>
#include <random>
#include <algorithm>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};



bool WelcomeToTheJungle::isWinnable(std::vector<std::vector<int>> &distances) {
    if(getAxes() > 0)
        return true;

    for (auto el: exits) {
        if (distances[el.first][el.second] != 0) {
            return true;
        }
    }

    return false;

}

void WelcomeToTheJungle::make_unsolvable(humanPlayer& p) {
    for(auto exit: exits) {
        findWinnablePath({exit.first, exit.second}, p);

        std::random_device rd;
        std::mt19937 gen(rd());

        int numberOfTrees = 2;

        std::uniform_int_distribution<int> distribution1(1 , (int)winnablePath.size() - 1 );
        while (numberOfTrees-- > 0) {
            int tree = distribution1(gen);
            this->maze[winnablePath[tree].first][winnablePath[tree].second] = '#';
        }
    }
}

int& WelcomeToTheJungle::getAxes(){
    return this->axes;
}


void WelcomeToTheJungle::findWinnablePath(std::pair<int, int> exit, humanPlayer &p) {
    if (!winnablePath.empty())
        winnablePath.clear();

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> distances(mazeWidth, std::vector<int>(mazeHeight, -1));
    std::vector<std::vector<char>> visited(mazeWidth, std::vector<char>(mazeHeight, '0'));
    q.emplace(p.getX(), p.getY());
    distances[p.getX()][p.getY()] = 0;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        visited[row][col] = '1';
        for (int i = 0; i < 4; ++i) {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (isValidCell(nx, ny) && this->maze[nx][ny] == '.' && visited[nx][ny] != '1') {
                q.emplace(nx, ny);
                distances[nx][ny] = distances[row][col] + 1;
            }
        }
    }

    std::pair<int, int> curr = exit;
    winnablePath.push_back(curr);

    while (curr.first != p.getX() || curr.second != p.getY()) {
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (isValidCell(nx, ny) && distances[nx][ny] == distances[curr.first][curr.second] - 1) {
                winnablePath.emplace_back(nx, ny);
                curr = {nx, ny};
                break;
            }
        }
    }
}


void WelcomeToTheJungle::setDistancesFromPlayer(humanPlayer &p, std::vector<std::vector<int>> &distances) {
    for (int i = 0; i < mazeWidth; ++i) {
        for (int j = 0; j < mazeHeight; ++j) {
            distances[i][j] = 0;
        }
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<char>> visited(mazeWidth, std::vector<char>(mazeHeight, '0'));
    q.emplace(p.getX(), p.getY());

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        visited[row][col] = '1';

        for (int i = 0; i < 4; ++i) {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (isValidCell(nx, ny) && this->maze[nx][ny] == '.' && visited[nx][ny] == '0') {
                q.emplace(nx, ny);
                distances[nx][ny] = distances[row][col] + 1;
            }
        }
    }
}
