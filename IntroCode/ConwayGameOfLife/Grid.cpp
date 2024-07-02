//
// Created by hayley on 2024/07/02.
//

#include "Grid.h"

void Grid::create(int row, int col) {
    cells[row][col].create();
}

void Grid::draw() {
    std::cout << "\x1b[2J";

    for(int i = 0; i < rowMax; i++) {
        for(int j = 0; j < colMax; j++) {
            cells[i][j].draw(i,j);
        }
    }
}

void Grid::randomize() {
    const int factor = 5;
    const int cutOff = RAND_MAX/factor;
    time_t now;
    time(&now);

    for(int i = 1; i < rowMax; i++) {
        for(int j = 1; j < colMax; j++){
            if(rand()/cutOff == 0) create(i,j);
        }
    }
}

bool Grid::willSurvive(int row, int col) {
    if(!cells[row][col].isAlive()){
        return false;
    }
    int neighbors = cells[row-1][col-1].isAlive() + cells[row-1][col].isAlive() +
        cells[row-1][col+1].isAlive() +
        cells[row][col-1].isAlive() +
        cells[row][col+1].isAlive() +
        cells[row+1][col-1].isAlive() +
        cells[row+1][col].isAlive() +
        cells[row+1][col+1].isAlive();

    if(neighbors < min_neighbours || neighbors > max_neighbours) {
        return false;
    }
  return true;
}

bool Grid::willCreate(int row, int col) {
    if(cells)
}




