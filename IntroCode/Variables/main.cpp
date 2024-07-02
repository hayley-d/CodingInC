#include <iostream>

#include "Url.h"

int passByValue(int y) {
    std::cout << "This is the address of y: " << &y << std::endl;
    return y; //creates another copy of y
}

int passByAddress(int* ptr) {
    *ptr = 8;
    return *ptr;
}

void passByReference(int& y) {
    y = 10;
}

void constRef(const int& y) {
    std::cout << "This is the value of the const ref: " << y << std::endl;
}

int main() {
    int x = 7; //create a local variable
    int z = passByValue(x); // creates another copy

    std::cout << "This is the address of x: " << &x << std::endl;
    std::cout << "This is the address of z: " << &z << std::endl;

    std::cout << "The value of x is " << x << std::endl;
    z = passByAddress(&x);
    std::cout << "The value of x is " << x << std::endl;
    std::cout << "The address of z is " << &z << std::endl;

    passByReference(x);
    std::cout << "The value of x is " << x << std::endl;

    int* ptr = new int{36}; //Allocates memory for a single int
    *ptr = 5;
    delete ptr;
    int* arr = new int[10]; //Allocates memory for an array of 10 ints on heap
    delete [] arr;


    Url* url = new Url("https","www.example.com/index.html");
    std::cout << url->display() << std::endl;



    return 0;
}
