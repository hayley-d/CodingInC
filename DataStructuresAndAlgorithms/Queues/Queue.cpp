//
// Created by hayley on 2024/06/22.
//

#include "Queue.h"

#include <iostream>

Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

Queue::Queue(int value) {
    this->head = new Node(value);
    this->tail = head;
    this->length = 1;
}

Queue::~Queue() {
   Node* temp = head;
    while(head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void Queue::printQueue() {
    Node* temp = head;
    while(temp) {
        std::cout << temp->value;
        temp = temp->next;
        if(temp) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

bool Queue::isEmpty() {
    return head == nullptr;
}

int Queue::peek() {
    if(!head) return -1;
    return head->value;
}

void Queue::dequeue() {
    if(!head) return;
    if(length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }else if(length == 2) {
        delete head;
        head = tail;
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length--;
}

void Queue::enqueue(int value) {
    if(!head) {
        head = new Node(value);
        tail = head;
    }
    else {
        tail->next = new Node(value);
        tail = tail->next;
    }
    length++;
}







