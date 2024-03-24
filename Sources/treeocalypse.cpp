#include "../Includes/treeocalypse.h"
#include "../Includes/humanplayer.h"
#include <queue>
#include <vector>
#include <random>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

Treeocalypse::Treeocalypse() {
    distances.resize(mazeHeight,std::vector<int>(mazeWidth,0));
}




void Treeocalypse::setDistancesFromPlayer(humanPlayer& p){
  for(int i = 0;i<mazeWidth;++i){
      for(int j = 0;j<mazeHeight;++j){
          this->distances[i][j] = 0;
      }
  }
    std::queue<std::pair<int,int>> q;
    q.emplace(p.getX(),p.getY());
    while(!q.empty()){
    auto [row,col] = q.front();
    q.pop();

    for(int i =0;i<4 ;++i){
        int  nx = row + dx[i];
        int  ny = col + dy[i];

        if(isBorderCell(nx,ny) && this->maze[nx][ny] == '.'){
            q.emplace(nx,ny);
            this->distances[nx][ny] = this->distances[row][col] + 1;
        }
     }
    }
}


void Treeocalypse::planting() {

    auto generateNumber = [](int minValue, int maxValue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minValue, maxValue);
        return dis(gen);
    };

    if(isWinnable()){
        for(int i = 0;i<3;++i){
            while (true){
                int x = generateNumber(0,mazeWidth - 1);
                int y = generateNumber(0,mazeWidth - 1);
                if(this->maze[x][y] == '.' && this->distances[x][y] < 10){
                    plantedTrees.push_back(Tree(x,y));
                    break;
                }
            }
        }
    }
        for(auto t:plantedTrees){
            if(t.growth()){
                this->maze[t.getX()][t.getY()] = '#';
            }
        }

}

bool Treeocalypse::isWinnable() {
        if(this->exits.size() == 2){
        if(this->maze[this->exits[0].first][this->exits[0].second] == 0 && this->maze[this->exits[1].first][this->exits[1].second] == 0){
            return false;
        }
    }
        else{
            if(this->maze[this->exits[0].first][this->exits[0].second] == 0){
                return false;
            }
        }
        return true;
}


