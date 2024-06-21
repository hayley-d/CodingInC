//
// Created by hayley on 2024/06/21.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"



class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList();
    LinkedList(int value);

    ~LinkedList();

    bool contains(int value);
    Node* get(int index);
    void set(int value,int index);

    bool append(int value);
    bool prepend(int value);
    bool insert(int value,int index);

    bool removeLast();
    bool removeFirst();
    bool remove(int index);

    void swapFirstLast();
    void reverse();
    bool isPalindrome();
    void swapPairs();

};



#endif //LINKEDLIST_H
