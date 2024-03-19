#pragma once
#include "labyrinth.h"

class WelcomeToTheJungle:public Labyrinth{
private:
    void make_unsolvable();
    bool isGameOver()  override;
};