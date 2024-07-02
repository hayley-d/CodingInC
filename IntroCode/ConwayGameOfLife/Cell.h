//
// Created by hayley on 2024/07/02.
//

#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "Life.h"

class Cell {
bool alive;
public:
    Cell() : alive(false){};
    void draw(int row, int col);
    void create(): alive(true){};
    void erase() : alive(false) {};

    bool isAlive() const{return alive;}
};



#endif //CELL_H
