//
// Created by hayley on 2024/07/02.
//

#include "Entity.h"

Entity::Entity(std::string name, double weight) {
    this->name = name;
    this->weight = weight;
}

Entity::Entity(const Entity &e) {
    this->name = e.name;
    this->weight = e.weight;
}

Entity &Entity::operator=(const Entity &other) {
    if(this == &other) return *this;
    this->name = other.name;
    this->weight = other.weight;
    return *this;
}

