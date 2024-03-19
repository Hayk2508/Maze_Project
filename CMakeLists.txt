cmake_minimum_required(VERSION 3.26)
project(Maze_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Maze_Project main.cpp
        game.cpp
        humanplayer.cpp
        humanplayer.h
        labyrinth.cpp
        labyrinth.h
        player.h
        treeocalypse.cpp
        treeocalypse.h
        welcometothejungle.cpp
        welcometothejungle.h)
