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
    Node *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
    Node *temp = this->head;
    while (temp) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

bool LinkedList::contains(int value) {
    if (this->length == 0) {
        return false;
    }

    Node *temp = this->head;

    while (temp) {
        if (temp->value == value) {
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
    if (this->head == nullptr) {
        this->head = new Node(value);
        this->tail = head;
    } else {
        if (contains(value)) {
            return;
        }
        tail->next = new Node(value);
        tail = tail->next;
    }
    length++;
}

int LinkedList::removeLast() {
    int num = -1;

    //check if the list is empty
    if (head == nullptr) {
        return -1;
    }

    if (length == 1) {
        //Only one element in the list
        num = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *temp = this->head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        //temp next node is the last node
        //temp will become the new tail node
        num = temp->next->value; //get the value of the last node
        delete temp->next;
        temp->next = nullptr;
        tail = temp;
    }
    length--;
    return num;
}

int LinkedList::removeFirst() {
    //Check if the list is empty
    int num = -1;
    if (head == nullptr) {
        return -1;
    }
    num = head->value;
    if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
    length--;
    return num;
}

void LinkedList::prepend(int value) {
    if (!contains(value)) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (length == 0) {
            tail = head;
        }
        length++;
    }
}

int LinkedList::removeValue(int value) {
    if(head == nullptr) {
        return -1;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp) {
        if (temp->value == value) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found, return -1
    if (temp == nullptr) {
        return -1;
    }

    //temp is the node to delete

    if (temp == head) {
        //delete the head
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    }  else {
        // Deleting a middle or tail node
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
    }

    delete temp;
    length--;
    return value;
}

bool LinkedList::insert(int index, int value) {
    if(length < index || index < 0) {
        return false;
    }

    if(index == 0) {
        prepend(value);
    }
    else if(index == length) {
         append(value);
     }
    else {
        Node* temp = head;
        Node* prev = nullptr;

        for(int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = new Node(value,temp);
        length++;
    }
    return true;
}

