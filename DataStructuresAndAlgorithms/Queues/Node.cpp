//
// Created by hayley on 2024/06/22.
//

#include "Node.h"

Node::Node() {
    this->next = nullptr;
    this->value = -1;
}

Node::Node(int value) {
    this->next = nullptr;
    this->value = value;
}

