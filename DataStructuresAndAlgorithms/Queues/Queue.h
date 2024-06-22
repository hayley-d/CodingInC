//
// Created by hayley on 2024/06/22.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
public:
    Node* head;
    Node* tail;
    int length;

    Queue();
    Queue(int value);
    ~Queue();

    void printQueue();
    bool isEmpty();

    void enqueue(int value);
    void dequeue();
    int peek();

};



#endif //QUEUE_H
