//
// Created by hayley on 2024/06/20.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include <string>

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    explicit LinkedList(int value);
    LinkedList();
    ~LinkedList();
    void append(int value);
    void prepend(int value);
    bool insert(int index,int value);
    void printList();
    int removeFirst();
    int removeLast();
    int removeValue(int value);
    bool contains(int value);
};



#endif //LINKEDLIST_H
