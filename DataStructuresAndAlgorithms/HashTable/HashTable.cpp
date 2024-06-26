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



