#pragma once


class Game{
public:
    virtual void play();
    static void clearConsole();
    static void start ();
    static void showInfo();
    static void Credits();
    static void play_music(const char *path);
};







