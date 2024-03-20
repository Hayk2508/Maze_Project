#pragma once


class Game{
public:
    virtual void play();
    virtual void draw();
    static void clearConsole();
    void start () const;
    void showInfo() const;
    void Credits() const;
    void play_music() const;
};







