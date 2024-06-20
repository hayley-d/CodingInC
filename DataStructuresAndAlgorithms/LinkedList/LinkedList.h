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
    void removeNode(int index);
    bool contains(int value);
    Node* get(int index);
    bool set(int index,int value);
    void reverse();
    Node* findMiddleNode();
    bool hasLoop();
    Node* findKthFromEnd(int k);
    void partitionList(int x);
    void removeDuplicates();
    int binaryToDecimal();
    void reverseBetween(int m, int n);
};



#endif //LINKEDLIST_H
