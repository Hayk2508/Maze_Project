cmake_minimum_required(VERSION 3.26)
project(Maze_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Maze_Project Sources/main.cpp
        Sources/game.cpp
        Sources/humanplayer.cpp
        Includes/humanplayer.h
        Sources/labyrinth.cpp
        Includes/labyrinth.h
        Includes/player.h
        Sources/treeocalypse.cpp
        Includes/treeocalypse.h
        Sources/welcometothejungle.cpp
        Includes/welcometothejungle.h
        Includes/tree.h
        Sources/tree.cpp
        Sources/tree.cpp
)

target_link_libraries(Maze_Project winmm)
