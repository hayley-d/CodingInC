#include <iostream>

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



    return 0;
}
