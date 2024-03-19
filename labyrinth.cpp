#include "labyrinth.h"
#include "treeocalypse.h"
#include "welcometothejungle.h"
#include "humanplayer.h"
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <windows.h>
#include <algorithm>
#include <queue>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};


void Labyrinth::play() {
     std::string input;
     std::cout << "Fine! Now choose one of the modes of the Game Labyrinth by writing its number\n";
     std::cout << "1.Welcome to the jungle\n" << "2.Treeocalypse\n";

    while(true) {
        std::cin >> input;
        if (input == "1") {
            std::cout << "Fine! Game is initializing\n";
            Sleep(400);
            system("cls");
            launchWelcomeToTheJungle();
        }
         else if (input == "2") {
            std::cout << "Fine! Game is initializing\n";
            Sleep(400);
            system("cls");
            launchTreeocalypse();
        }
     }
}

[[noreturn]] void Labyrinth::launchTreeocalypse() {

    auto cut_surrounding_trees = [&](int x, int y){
        maze[x-1][y] = '.';
        maze[x-1][y-1] = '.';
        maze[x-1][y+1] = '.';
        maze[x+1][y] = '.';
        maze[x+1][y-1] = '.';
        maze[x +1][y +1] = '.';
        maze[x][y -1] = '.';
        maze[x][y +1] = '.';
    };
    auto generateNumber = [](int minValue, int maxValue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minValue, maxValue);
        return dis(gen);
    };

    humanPlayer player;
    std::string  input;
    std::cout<<"Choose your nickname!\n";
    std::cin>>input;
    player.setNickname(input);
    system("cls");

    Treeocalypse tMaze;
    int startX = generateNumber(9,11);
    int startY = generateNumber(9,11);

    tMaze.maze[startX][startY] = '@';
    tMaze.generateGrid(startX,startY);
    tMaze.draw();
    cut_surrounding_trees(startX, startY);
    tMaze.draw();
    tMaze.generateExits(startX, startY);
    tMaze.draw();

    player.setX(startX);
    player.setY(startY);
    while(true){
        if(player.move(tMaze.maze)){
            clearConsole();
            Sleep(100);
            tMaze.draw();
        }
        //tMaze.planting();
    }
}

bool Labyrinth::isValidCell(int x,int y){
    return y >= 0 && y < mazeWidth && x >= 0 && x < mazeHeight;
}

void Labyrinth::launchWelcomeToTheJungle() {
    WelcomeToTheJungle maze;
}
    Labyrinth::Labyrinth() {
    maze.resize(mazeHeight,std::vector<char>(mazeWidth,'#'));
}

void Labyrinth::generateGrid(int x,int y) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if(maze[x][y]!='@'){
        maze[x][y] = '.';
    }

    std::vector<int> directions = {0, 1, 2, 3};
    std::shuffle(directions.begin(), directions.end(), gen);


    for (int dir : directions) {
        int nx = x + dx[dir] * 2;
        int ny = y + dy[dir] * 2;
        if (isValidCell(nx, ny) && maze[nx][ny] == '#') {
            maze[x + dx[dir]][y + dy[dir]] = '.';
            generateGrid(nx,ny);
        }
    }
}

bool Labyrinth::isGameOver() {

}

void Labyrinth::draw() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    COORD position;
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(hConsole, position);
    for (const auto& row : maze) {
        for (char cell : row) {
            if (cell == '#') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                std::cout << '#';
            } else if (cell == '@') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << '@';
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
}

void Labyrinth::generateExits(int x, int y) {

    auto isBorder = [](int x, int y){
            return y == 0 || y == mazeWidth - 1 || x == 0 || x == mazeHeight - 1;

    };

   for(int i = 0; i< mazeWidth;++i)
       maze[0][i] = '#';
   for(int i = 0;i< mazeHeight;++i)
       maze[i][0] = '#';
   for(int i = 0;i < mazeHeight;++i)
       maze[mazeWidth - 1][i] = '#';
   for(int i =0;i< mazeWidth;++i)
       maze[i][mazeHeight -1] = '#';

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> visited
    (mazeHeight , std::vector<int>(mazeWidth,'0'));
    std::vector<std::pair<int,int>> exits;

    q.emplace(x, y);
    int count = 0;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        visited[row][col] = '1';

        if(count == 2){
            break;
        }

        for(int i =0 ; i < 4 ; ++i ){
            int n_row = row + dx[i];
            int n_col = col + dy[i];
         if(isBorder(n_row,n_col)){
             ++count;
             exits.emplace_back(n_row, n_col);
             continue;
         }

         if(n_row > 0 && n_row <mazeWidth -1  && n_col >0 && n_col < mazeHeight - 1
         && visited[n_row][n_col] == '0'  && maze[n_row][n_col] == '.'){
             q.emplace(n_row, n_col);
         }
        }


    }

    for(auto exit: exits)
    maze[exit.first][exit.second] = '.';


}
