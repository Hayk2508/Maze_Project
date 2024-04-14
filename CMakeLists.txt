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
)
target_link_libraries(Maze_Project winmm)
#configure_file(
#        "C:/Users/User/Desktop/Projects/Maze_Project/Musics/Crazy Frog - Axel F (Official Video) (256 kbps) (mp3cut.net).wav"
#        "${CMAKE_CURRENT_BINARY_DIR}/music_file.wav"
#        COPYONLY
#)
