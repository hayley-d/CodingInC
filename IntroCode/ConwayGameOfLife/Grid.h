//
// Created by hayley on 2024/07/02.
//

#ifndef GRID_H
#define GRID_H
#include <string>
#include <vector>
#include <cstdlib>
#include "Cell.h"

class Grid {
Cell cells[rowMax+2][colMax+2];

public:
    void create(int row, int col);
    void draw();
    void randomize();
    bool willCreate(int row, int col);
    bool willSurvive(int row, int col);
    void update(const Grid& other);
};

void calculate(Grid& one, Grid& two);

#endif //GRID_H
