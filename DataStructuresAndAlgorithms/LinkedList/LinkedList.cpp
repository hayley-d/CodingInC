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

//destructor
LinkedList::~LinkedList() {
    // Need to go through an manually delete all the nodes in the list
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

bool LinkedList::contains(int value) {
    if(this->length == 0) {
        return false;
    }

    Node* temp = this->head;

    while(temp) {
        if(temp->value == value) {
            return true;
        }
    }
    return false;
}

/*
 * Add the node to the end of the list
 */
void LinkedList::append(int value) {
    //Check if the list is empty
    if(this->head == nullptr) {
        this->head = new Node(value);
        this->tail = head;
    }
    else {
        if(contains(value)) {
            return;
        }
        tail->next = new Node(value);
        tail = tail->next;
    }
    length++;
}



