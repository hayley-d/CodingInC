//
// Created by hayley on 2024/06/21.
//

#include "LinkedList.h"

#include <cmath>

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

bool LinkedList::contains(int value)
{
    if(head == nullptr) return false;
    Node* temp = head;
    while(temp) {
        if(temp->value == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* LinkedList::get(int index) {
    if(head == nullptr || index < 0 || index >= length) return nullptr;

    Node* temp = head;

    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp;
}

void LinkedList::set(int value,int index) {
    Node* temp = get(index);
    if(temp) {
        temp->value = value;
    }
}

bool LinkedList::append(int value) {
    if(contains(value)) return false;
    if(head == nullptr) {
        this->head = new Node(value);
        this->tail = head;
    }
    else {
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
    return true;
}

bool LinkedList::prepend(int value) {
    if(contains(value)) return false;
    if(head == nullptr) {
        this->head = new Node(value);
        this->tail = head;
    }
    else {
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
    return true;
}

bool LinkedList::insert(int value,int index) {
    if(contains(value) || index < 0 || index > length) return false;
    if(head == nullptr) {
        this->head = new Node(value);
        this->tail = head;
    }
    else if(index == 0) {
        prepend(value);
        return true;
    }
    else if(index == length) {
        append(value);
        return true;
    }
    else {
        Node* newNode = new Node(value);
        Node* temp = get(index-1);
        if(temp) {
            //if temp != null
            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
    length++;
    return true;
}

bool LinkedList::removeLast() {
    if(head == nullptr) return false;

    if(length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* temp = tail;

        tail = tail->prev;

        delete temp;

        tail->next = nullptr;
    }
    length--;
    return true;
}

bool LinkedList::removeFirst() {
    if(head == nullptr) return false;

    if(length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* temp = head;

        head = head->next;

        delete temp;

        head->prev = nullptr;
    }
    length--;
    return true;
}

bool LinkedList::remove(int index) {
    if(head == nullptr || index < 0 || index >= length) return false;
    Node* temp = get(index);
    if(temp && temp == head) {
        head = head->next;
        head->prev = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;
    }
    if(temp && temp == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;
    }

    if(temp && temp->prev) {
        temp->prev->next = temp->next;
        if(temp->next) {
            temp->next->prev = temp->prev;
        }
    }


    length--;
    return true;
}

/*
 * Swaps the node of the first and last node in the list
 */
void LinkedList::swapFirstLast() {
    if(length < 2) return;
    if(length == 2) {
        Node*temp = head;
        head = tail;
        tail = temp;

        head->next = tail;
        head->prev = nullptr;

        tail->prev = head;
        tail->next = nullptr;

        return;
    }
    Node* beforeTail = tail->prev;
    Node* afterHead = head->next;

    Node*temp = head;
    this->head = tail;
    this->tail = temp;

    afterHead->prev = head;
    head->next = afterHead;
    head->prev = nullptr;

    beforeTail->next = tail;
    tail->prev = beforeTail;
    tail->next = nullptr;
}

void LinkedList::reverse() {
    if(length < 2) return;

    Node* curr = head;

    for(int i = 0; i < length; i++) {
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    curr = head;
    head = tail;
    tail = curr;
}

/*
 * list with 0 or 1 nodes is a plaindrome
 */
bool LinkedList::isPalindrome() {
    if(!head || length == 1) return true;

    Node* front = head;
    Node* end = tail;

    while(front && end) {
        if(front->value != end->value) {
            return false;
        }
        if(front == end) {
            return true;
        }
        front = front->next;
        end = end->prev;
    }
    return true;
}

/*
 * swap each two adjacent nodes
 * 1->2->3->4 becomes 2->1->4->3
 * 1->2->3->4->5 becomes 2->1->4->5->3
 */
void LinkedList::swapPairs() {
    if(!head || length < 2) return;

    Node* n1 = head;
    Node* n2 = head->next;



    while(n1 && n2) {
        Node* temp = n2->next;

        if(n1 == head) {
            head = n2;
        }

        if(n2 == tail) {
            tail = n1;
        }

        n2->prev = n1->prev;
        n2->next = n1;
        if (n1->prev) {
            n1->prev->next = n2;
        }
        n1->prev = n2;
        n1->next = temp;
        if (temp) {
            temp->prev = n1;
        }

        n1 = temp;
        if(n1) {
            n2 = n1->next;
            if(!n2) {
                n2 = n1;
                n1 = n1->prev;
            }
        }
    }
}




