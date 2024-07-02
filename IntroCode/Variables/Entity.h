//
// Created by hayley on 2024/07/02.
//

#ifndef ENTITY_H
#define ENTITY_H

#include<string>
#include<vector>
#include<iomanip>

class Entity {
private:
    std::string name;
    double weight;
    Entity& operator=(const Entity& other);

public:
    Entity(std::string name,double weight); //constructor
    Entity(const Entity& e);


};



#endif //ENTITY_H
