//
// Created by hayley on 2024/06/20.
//

#include "LinkedList.h"

#include <iomanip>
#include<iostream>
#include <string>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

LinkedList::LinkedList(int value) {
    //Create the head
    this->head = new Node(value);

    //Initialize tail
    this->tail = head;

    //Initialize length
    this->length = 1;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
    Node* temp = this->head;
    while(temp) {
        std::cout<<temp->value<<std::endl;
        temp = temp->next;
    }
}

