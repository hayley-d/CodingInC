//
// Created by hayley on 2024/06/26.
//

#include "HashTable.h"

HashTable::HashTable() {
    for(int i = 0; i < SIZE; i++) {
        dataMap[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for(int i = 0; i < SIZE; i++) {
        Node* head = dataMap[i];
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
}

void HashTable::printTable() {
    for(int i = 0; i < SIZE; i++) {
        std::cout << "Index " << i << ": ";
        if(dataMap[i]) {
            std::cout << "Contains => ";
            Node* temp = dataMap[i];
            while (temp) {
                std::cout << "{" << temp->key << ", " << temp->value << "}";
                temp = temp->next;
                if (temp) std::cout << ", ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
}

int HashTable::hash(std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue *  23) % SIZE;
    }
    return hash;
}

int HashTable::get(std::string key) {
    int index = hash(key);
    Node* temp = dataMap[index];
    while (temp != nullptr) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return 0;
}

void HashTable::set(std::string key, int value) {
    int i = hash(key);
    dataMap[i] = new Node(value,key);
    return;
}

std::vector<std::string> HashTable::keys() {
    std::vector<std::string> allKeys;
    for(int i = 0; i < SIZE; i++) {
        Node* temp = dataMap[i];
        while (temp != nullptr) {
            allKeys.push_back(temp->key);
            temp = temp->next;
        }
    }
    return allKeys;
}






