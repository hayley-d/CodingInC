//
// Created by hayley on 2024/06/26.
//

#include "Node.h"

#include <utility>

Node::Node(int value, std::string key) {
    this->value = value;
    this->key = std::move(key);
}


