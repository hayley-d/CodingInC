//
// Created by hayley on 2024/06/21.
//

#include "LinkedList.h"

//Constructor
LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

//Constructor
LinkedList::LinkedList(int value) {
    this->head = new Node(value);
    this->tail = head;
    this->length = 1;
}

// Destructor
LinkedList::~LinkedList() {
    Node* temp = head;
    while(head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

bool LinkedList::contains(int value){}
Node* LinkedList::get(int index){}
void LinkedList::set(int value,int index){}

bool LinkedList::append(int value){}
bool LinkedList::prepend(int value){}
bool LinkedList::insert(int value,int index){}

bool LinkedList::removeLast(){}
bool LinkedList::removeFirst(){}
bool LinkedList::remove(int value, int index){}
bool LinkedList::remove(int value){}
