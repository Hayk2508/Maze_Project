#pragma once

class Tree{
public:
    Tree(int x_,int y_);
    bool growth();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
private:
    int countdown = 11;
    int x;
    int y;
};