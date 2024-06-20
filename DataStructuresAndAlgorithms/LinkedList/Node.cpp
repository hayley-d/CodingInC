//
// Created by hayley on 2024/06/20.
//

#include "Node.h"

Node::Node(int v, Node *n) : value(v), next(n){}

Node::Node(int value){
    this->value= value;
    this->next = nullptr;
}

