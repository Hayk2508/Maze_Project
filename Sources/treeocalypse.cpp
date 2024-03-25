#include "../Includes/treeocalypse.h"
#include "../Includes/humanplayer.h"
#include <queue>
#include <vector>
#include <random>
#include <ctime>
#include <set>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

Treeocalypse::Treeocalypse() {
    distances.resize(mazeHeight,std::vector<int>(mazeWidth,0));
}

void Treeocalypse::findEmptyCells() {
    this->emptyCells.resize(0);
    for(int i = 0;i<mazeWidth;++i){
        for(int j = 0;j<mazeHeight;++j){
            if(maze[i][j] == '.'){
                this->emptyCells.emplace_back(i,j);
            }
        }
    }
}



void Treeocalypse::setDistancesFromPlayer(humanPlayer& p){
  for(int i = 0;i<mazeWidth;++i){
      for(int j = 0;j<mazeHeight;++j){
          this->distances[i][j] = 0;
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
            this->distances[nx][ny] = this->distances[row][col] + 1;
        }
     }
    }
}


void Treeocalypse::planting() {


    if(isWinnable()){
        if(this->emptyCells.size()> 3){
            int count = 0;
            std::set<std::pair<int,int>> willBePlanted;
            while(count!=3){
                std::srand(static_cast<unsigned int>(std::time(nullptr)));
                int randomIndex = std::rand() % this->emptyCells.size();
                std::pair<int, int> randomElement = this->emptyCells[randomIndex];
                if(this->distances[randomElement.first][randomElement.second] < 10 && !(willBePlanted.count({randomElement.first,randomElement.second}))){
                    willBePlanted.insert({randomElement.first,randomElement.second});
                    ++count;
                }
            }
        }

    }
    else{
        clearConsole();
        std::cout << "You lost the game:(\n";
    }
        for(int i = 0;i<plantedTrees.size();++i){
            if(plantedTrees[i].growth()){
                this->maze[plantedTrees[i].getX()][plantedTrees[i].getY()] = '#';
            }
        }

}

bool Treeocalypse::isWinnable() {
        if(this->exits.size() == 2){
        if(this->distances[this->exits[0].first][this->exits[0].second] == 0 && this->distances[this->exits[1].first][this->exits[1].second] == 0){
            return false;
        }
    }
        else{
            if(this->distances[this->exits[0].first][this->exits[0].second] == 0){
                return false;
            }
        }
        return true;
}


