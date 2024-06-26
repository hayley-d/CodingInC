//
// Created by hayley on 2024/06/26.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
    int hash(std::string key);

public:
    HashTable();
    ~HashTable();
    void printTable();
    void set(std::string key,int value);
    int get(std::string key);
    std::vector<std::string> HashTable::keys();
};



#endif //HASHTABLE_H
