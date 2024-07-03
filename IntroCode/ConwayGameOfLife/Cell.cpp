//
// Created by hayley on 2024/07/02.
//

#include "Cell.h"

void Cell::draw(int row, int col) {
std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
  std::cout << (alive ? live_cell : dead_cell);
}
