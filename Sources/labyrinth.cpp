#include "../Includes/labyrinth.h"
#include "../Includes/treeocalypse.h"
#include "../Includes/welcometothejungle.h"
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


void Labyrinth::play() {

    std::string input;
    std::cout << "Fine! Now choose one of the modes of the Game Labyrinth by writing its number\n";
    std::cout << "1.Welcome to the jungle\n" << "2.Treeocalypse\n";

    while (true) {
        std::cin >> input;
        if (input == "1") {
            std::cout << "Fine! Game is initializing\n";
            Sleep(400);
            system("cls");
            launchWelcomeToTheJungle();
        } else if (input == "2") {
            std::cout << "Fine! Game is initializing\n";
            Sleep(400);
            system("cls");
            launchTreeocalypse();
        } else {
            std::cout << "Please type only the numbers that mentioned above\n";
        }
    }
}


[[noreturn]] void Labyrinth::launchTreeocalypse() {
    Treeocalypse tMaze;
    int axes = 0;


    auto generateNumber = [](int minValue, int maxValue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minValue, maxValue);
        return dis(gen);
    };
    auto cut = [&](int x, int y) {
        tMaze.maze[x - 1][y] = '.';
        tMaze.maze[x + 1][y] = '.';
        tMaze.maze[x][y - 1] = '.';
        tMaze.maze[x][y + 1] = '.';
    };

    humanPlayer player;
    std::string input;
    std::cout << "Choose your nickname!\n";
    std::cin >> input;
  
    play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/Crazy Frog - Axel F (Official Video) (256 kbps) (mp3cut.net).wav");
    player.setNickname(input);
    system("cls");

    int startX = generateNumber(12, 14);
    int startY = generateNumber(12, 14);


    tMaze.maze[startX][startY] = '@';
    tMaze.generateGrid(startX, startY);
    cut(startX, startY);
    tMaze.generateExits(startX, startY);
  
    tMaze.draw(axes, "T");

    player.setX(startX);
    player.setY(startY);

    tMaze.findEmptyCells();

    std::vector<std::vector<int>> distances(mazeHeight, std::vector<int>(mazeWidth));
    tMaze.setDistancesFromPlayer(player, distances);

    std::vector<std::vector<int>> distancesAfterEachMove = distances;

    while (tMaze.isWinnable(distancesAfterEachMove)) {
        tMaze.setDistancesFromPlayer(player, distancesAfterEachMove);
        if (player.move(tMaze.maze, axes)) {

            if (isBorderCell(player.getX(), player.getY())) {
                system("cls");
                Sleep(500);
                std::cout << "Congratulations " << player.getNickname() << ", you won the game!\n";
                play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/1984a9f3474ab6d.wav");
                Sleep(4000);
                exit(0);
            }

            tMaze.planting(distancesAfterEachMove);
            Sleep(125);
            clearConsole();
            tMaze.draw(axes, "T");
        }
    }
    system("cls");
    Sleep(1000);
    std::cout<<"ALL THE ROADS TO EXIT ARE IMPASSABLE NOW \n";
    Sleep(2500);
    play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/fail-wha-wha-version.wav");
    std::cout << "Game Over :( \n";
    Sleep(6000);
    exit(0);
}

bool Labyrinth::isValidCell(int x, int y ) {

    return y >= 0 && y < mazeWidth && x >= 0 && x < mazeHeight;
}

void Labyrinth::launchWelcomeToTheJungle() {
    WelcomeToTheJungle wMaze;

    auto generateNumber = [](int minValue, int maxValue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minValue, maxValue);
        return dis(gen);
    };
    auto close = [&](int x, int y) {
        wMaze.maze[x - 1][y] = '#';
        wMaze.maze[x + 1][y] = '#';
        wMaze.maze[x][y - 1] = '#';
        wMaze.maze[x][y + 1] = '#';
    };


    humanPlayer player;
    std::string input;
    std::cout << "Choose your nickname!\n";
    std::cin >> input;
    play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/Crazy Frog - Axel F (Official Video) (256 kbps) (mp3cut.net).wav");
    player.setNickname(input);
    system("cls");

    int startX = generateNumber(11, 15);
    int startY = generateNumber(11, 15);


    wMaze.maze[startX][startY] = '@';
    wMaze.generateGrid(startX, startY);
    close(startX, startY);
    wMaze.generateExits(startX, startY);

    player.setX(startX);
    player.setY(startY);

    wMaze.make_unsolvable(player);
    wMaze.draw(wMaze.getAxes(), "W");



    std::vector<std::vector<int>> distances(mazeHeight, std::vector<int>(mazeWidth));
    wMaze.setDistancesFromPlayer(player, distances);

    while(wMaze.isWinnable(distances)){
        if(player.move(wMaze.maze, wMaze.getAxes())){
            wMaze.setDistancesFromPlayer(player, distances);

            if (isBorderCell(player.getX(), player.getY())) {
                system("cls");
                Sleep(500);
                std::cout << "Congratulations " << player.getNickname() << ", you won the game!\n";
                play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/1984a9f3474ab6d.wav");
                Sleep(4000);
                exit(0);
            }
            Sleep(125);
            clearConsole();
            wMaze.draw(wMaze.getAxes(), "W");
        }

    }

    system("cls");
    Sleep(1000);
    std::cout<<"YOU HAVE NO MORE AXES LEFT TO CLEAN THE ROAD TO EXIT!"<<std::endl;
    Sleep(2000);
    play_music("C:/Users/User/Desktop/Projects/Maze_Project/Musics/fail-wha-wha-version.wav");
    std::cout << "Game Over :( \n";
    Sleep(6000);
    exit(0);

}

Labyrinth::Labyrinth() {
    maze.resize(mazeHeight, std::vector<char>(mazeWidth, '#'));
}

void Labyrinth::generateGrid(int x, int y) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if (maze[x][y] != '@') {
        maze[x][y] = '.';
    }

    std::vector<int> directions = {0, 1, 2, 3};
    std::shuffle(directions.begin(), directions.end(), gen);


    for (int dir: directions) {
        int nx = x + dx[dir] * 2;
        int ny = y + dy[dir] * 2;
        if (isValidCell(nx, ny) && maze[nx][ny] == '#') {
            maze[x + dx[dir]][y + dy[dir]] = '.';
            generateGrid(nx, ny);
        }
    }
}

void Labyrinth::draw(int& axes, std::string game ) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    COORD position;
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(hConsole, position);

    int count = 0;
    for (const auto &row: maze) {
        for (char cell: row) {
            if (cell == '#') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                std::cout << std::setw(2) << '#';
            } else if (cell == '@') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << std::setw(2) << '@';

            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                std::cout << std::setw(2) << '.';
            }
        }
        count++;
        if(count == 4  && game == "W"){
            std::cout<<"                     AMOUNT OF AXES : "<<axes;
        }
        std::cout << std::endl;
    }
}

bool Labyrinth::isBorderCell(int x, int y) {
    return x == 0 || y == 0 || x == mazeWidth - 1 || y == mazeHeight - 1;
}

void Labyrinth::generateExits(int x, int y) {

    for (int i = 0; i < mazeWidth; ++i)
        maze[0][i] = '#';
    for (int i = 0; i < mazeHeight; ++i)
        maze[i][0] = '#';
    for (int i = 0; i < mazeHeight; ++i)
        maze[mazeWidth - 1][i] = '#';
    for (int i = 0; i < mazeWidth; ++i)
        maze[i][mazeHeight - 1] = '#';

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 2);

    int countOfExits = distribution(gen);
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> visited
            (mazeHeight, std::vector<int>(mazeWidth, '0'));

    q.emplace(x, y);

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        visited[row][col] = '1';

        if (exits.size() == countOfExits) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            if (isBorderCell(n_row, n_col)) {
                exits.insert({n_row, n_col});
                continue;
            }

            if (n_row > 0 && n_row < mazeWidth - 1 && n_col > 0 && n_col < mazeHeight - 1
                && visited[n_row][n_col] == '0' && maze[n_row][n_col] == '.') {
                q.emplace(n_row, n_col);
            }
        }


    }

    for (auto exit: exits)
        maze[exit.first][exit.second] = '.';


}
