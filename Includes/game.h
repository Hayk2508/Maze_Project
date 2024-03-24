#pragma once


class Game{
public:
    virtual void play();
    virtual void draw();
    static void clearConsole();
    static void start ();
    static void showInfo();
    static void Credits();
    void play_music() const;
};







