//
// Created by hayley on 2024/06/17.
//

#include "Cookie.h"

#include <iostream>

// Default constructor
Cookie::Cookie() : flavor("Chocolate Chip"), weight(50.0) {}

// Parameterized constructor
Cookie::Cookie(const std::string& flavor, double weight) : flavor(flavor), weight(weight) {}

// Destructor
Cookie::~Cookie() {
    std::cout << "Cookie destructor called for " << flavor << " cookie." << std::endl;
}

// Setter functions
void Cookie::setFlavor(const std::string& flavor) {
    this->flavor = flavor;
}

void Cookie::setWeight(double weight) {
    this->weight = weight;
}

// Member functions
void Cookie::bake() {
    std::cout << flavor << " cookie is being baked!" << std::endl;
}

void Cookie::eat() {
    std::cout << "Nom nom... Enjoying the " << flavor << " cookie!" << std::endl;
}

// Getter functions
std::string Cookie::getFlavor() const {
    return flavor;
}

double Cookie::getWeight() const {
    return weight;
}
