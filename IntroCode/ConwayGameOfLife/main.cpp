#include <iostream>

#include "Grid.h"

int main() {
    std::cout << "Conway's Game of Life" <<std::endl;
    std::cout << "Press return key to display a generation" << std::endl;

    std::cin.get();

    //Populate the grid for girst gen
    Grid currentGeneration;

    while(true) {
        currentGeneration.draw();

        std::cin.get();

        Grid nextGeneration;

        calculate(currentGeneration, nextGeneration);

        currentGeneration.update(nextGeneration);
    }
    std::cout << "\x1b[" << 0 << ";" << rowmax-1 <<"H";


    return 0;
}
