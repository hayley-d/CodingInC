//
// Created by hayley on 2024/06/22.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"


class Stack {

public:
    Node* top;
    int height;

    Stack();
    Stack(int value);
    ~Stack();

    void printStack();
    void push(int value);
    Node* pop();
};



#endif //STACK_H
