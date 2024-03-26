#include "../Includes/tree.h"



 Tree::Tree(int x_,int y_):x(x_),y(y_){

};
bool Tree::growth() {
    --this->countdown;
    if(this->countdown == 0){
        return true;
    }
    return false;
}
int Tree::getY() const {
    return y;
}
int Tree::getX() const {
    return  x;
}
