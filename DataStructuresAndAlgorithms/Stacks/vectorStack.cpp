//
// Created by hayley on 2024/06/22.
//

#include "vectorStack.h"

#include <iostream>

vectorStack::vectorStack() {
    this->stack = std::vector<int>();
}


std::vector<int> &vectorStack::getStack() {
    return stack;
}

void vectorStack::printStack() {
    for(int i = stack.size()-1; i >= 0; i-- ) {
        std::cout << stack[i] << std::endl;
    }
}

bool vectorStack::isEmpty() {
    return stack.empty();
}

int vectorStack::peek() {
    if(isEmpty()) {
        return -1;
    }
    else {
        return stack[stack.size()-1];
    }
}

void vectorStack::push(int value) {
    if(isEmpty()) return;
    stack.push_back(value);
}


int vectorStack::pop() {
    if(isEmpty()) return -1;
    int val = stack.back();
    stack.pop_back();
    return val;
}





