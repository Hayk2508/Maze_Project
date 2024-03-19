#pragma once


class Game{
public:
    virtual void play();
    virtual void draw();
    static void clearConsole();
    void start();
    void showInfo();
    void Credits();
    void play_music();
};







