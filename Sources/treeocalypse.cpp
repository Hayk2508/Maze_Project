#include "../Includes/treeocalypse.h"
#include <queue>
#include <vector>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};


void Treeocalypse::setDistancesFromPlayer(int px,int py,std::vector<std::vector<char>>& grid){
    std::queue<std::pair<int,int>> q;
    q.emplace(px,py);
    while(!q.empty()){
    auto [row,col] = q.front();


    for(int i =0;i<4 ;++i){
        int  nx = row + dx[i];
        int  ny = col + dy[i];

        if(isBorderCell(nx,ny) && grid[nx][ny] == '.'){
            q.emplace(nx,ny);
            distances[nx][ny] = distances[row][col] + 1;
        }
     }
    }
}


void Treeocalypse::planting() {

}

//void Treeocalypse::findWinnablePath(const int x, const int y) {
//    std::vector<std::vector<int>> maze_steps(mazeHeight, std::vector<int>(mazeWidth, 0));
//    std::queue<std::pair<int,int>> q;
//    q.emplace(x,y);
//
//    int count = 0;
//    while(!q.empty()){
//        auto [row, col] = q.front();
//        q.pop();
//
//        if(isBorderCell(row, col)){
//            count++;
//            if(count == exitCount)
//                break;
//        }
//
//        for(int i =0;i<4 ;++i){
//            int  nx = row + dx[i];
//            int  ny = col + dy[i];
//
//            if(isValidCell(nx, ny) && maze[nx][ny] != '@' && maze[nx][ny] =='.'
//            && maze_steps[nx][ny] == 0){
//                q.emplace(nx, ny);
//                maze_steps[nx][ny] = maze_steps[row][col] +1;
//            }
//        }
//
//    }
//}

void Treeocalypse::growth() {

}

