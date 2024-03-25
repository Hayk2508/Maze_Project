#include "../Includes/treeocalypse.h"
#include "../Includes/humanplayer.h"
#include <queue>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <set>
#include <memory>
#include <thread>
#include <windows.h>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};
std::vector<std::pair<int,int>> Treeocalypse::emptyCells;

void  Treeocalypse::setEmptyCell(int x, int y) {
    emptyCells.emplace_back(x,y);
}
void  Treeocalypse::removeEmptyCell(int x, int y) {
    auto pair_equals = [&](const std::pair<int, int>& p) {
        return p.first == x && p.second == y;
    };

    // Find the pair to remove
    auto it = std::find_if(emptyCells.begin(), emptyCells.end(), pair_equals);

    if (it != emptyCells.end()) {
        emptyCells.erase(it);
    }
}
void Treeocalypse::findEmptyCells() {
    for(int i = 0;i<mazeWidth;++i){
        for(int j = 0;j<mazeHeight;++j){
            if(maze[i][j] == '.'){
                this->emptyCells.emplace_back(i,j);
            }
        }
    }
}



void Treeocalypse::setDistancesFromPlayer(humanPlayer& p,std::vector<std::vector<int>>& distances){
  for(int i = 0;i<mazeWidth;++i){
      for(int j = 0;j<mazeHeight;++j){
          distances[i][j] = 0;
      }
  }
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<char>> visited(mazeWidth,std::vector<char>(mazeHeight,'0'));
    q.emplace(p.getX(),p.getY());
    while(!q.empty()){
    auto [row,col] = q.front();
    q.pop();
    visited[row][col] = '1';

    for(int i =0;i<4 ;++i){
        int  nx = row + dx[i];
        int  ny = col + dy[i];

        if(isValidCell(nx,ny) && this->maze[nx][ny] == '.' && visited[nx][ny] == '0'){
            q.emplace(nx,ny);
            distances[nx][ny] = distances[row][col] + 1;
        }
     }
    }
}


void Treeocalypse::planting(std::vector<std::vector<int>>& distances) {


    if(isWinnable(distances)){
        if(this->emptyCells.size()> 3){
            int count = 0;
            std::set<std::pair<int,int>> willBePlanted;
            std::vector<std::pair<int,int>> remainingCells = emptyCells;
            while(count!= 3 && !remainingCells.empty()){
                std::srand(static_cast<unsigned int>(std::time(nullptr)));
                int randomIndex = std::rand() % remainingCells.size();
                std::pair<int, int> randomElement = remainingCells[randomIndex];


                if(distances[randomElement.first][randomElement.second] < 10){
                    willBePlanted.insert({randomElement.first,randomElement.second});
                    ++count;
                }
                remainingCells.erase(remainingCells.begin() + randomIndex);
            }
            if(count == 3){
                for(auto& el:willBePlanted){
                    this->plantedTrees.emplace_back(el.first,el.second);
                    this->removeEmptyCell(el.first,el.second);
                }
            }

        }
    }
    else{
        clearConsole();
        Sleep(100);
        std::cout << "krvar\n";
        Sleep(1000);
        exit(0);
    }
        for(int i = 0;i<plantedTrees.size();++i){
            if(plantedTrees[i].growth()){
                this->maze[plantedTrees[i].getX()][plantedTrees[i].getY()] = '#';
                plantedTrees.erase(plantedTrees.begin() + i);
            }
        }

}

bool Treeocalypse::isWinnable(std::vector<std::vector<int>>& distances) {
        if(this->exits.size() == 2){
        if(distances[this->exits[0].first][this->exits[0].second] == 0 && distances[this->exits[1].first][this->exits[1].second] == 0){
            return false;
        }
    }
        else{
            if(distances[this->exits[0].first][this->exits[0].second] == 0){
                return false;
            }
        }
        return true;
}


