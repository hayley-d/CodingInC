//
// Created by hayley on 2024/06/22.
//

#include "Stack.h"
#include <iostream>

Stack::Stack() {
    this->top = nullptr;
    this->height = 0;
}

Stack::Stack(int value) {
    this->top = new Node(value);
    this->height = 1;
}

Stack::~Stack() {
    Node* temp = top;
    while(top) {
        top = top->next;
        delete temp;
        temp = top;
    }
}

void Stack::printStack() {
    Node* temp = top;
    while(temp) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

void Stack::push(int value) {
    if(!top) {
        top = new Node(value);
    }else {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    height++;
}

Node *Stack::pop() {
    if(!top) return nullptr;
    Node* temp = top;
    top = top->next;
    height--;
    return temp;
}



