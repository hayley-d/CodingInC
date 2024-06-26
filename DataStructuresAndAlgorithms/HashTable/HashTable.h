//
// Created by hayley on 2024/06/26.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <iostream>
#include <string>

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
public:
    HashTable();
    ~HashTable();
    void printTable();
};



#endif //HASHTABLE_H
