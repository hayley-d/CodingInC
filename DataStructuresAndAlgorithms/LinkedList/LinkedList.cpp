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
    if (head == nullptr) {
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
    } else {
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

void LinkedList::removeNode(int index){
    if(index < 0 || index >= length) return;

    if(index == 0) {
        removeFirst();
    }
    else if(index == length-1) {
        removeLast();
    }
    else {
        Node* temp = head;
        Node* prev = nullptr;

        for(int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        if(prev!= nullptr) {
            prev->next = temp->next;
        }
        delete temp;
        length--;
    }
}

bool LinkedList::insert(int index, int value) {
    if (length < index || index < 0) {
        return false;
    }

    if (index == 0) {
        prepend(value);
    } else if (index == length) {
        append(value);
    } else {
        Node *temp = head;
        Node *prev = nullptr;

        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = new Node(value, temp);
        length++;
    }
    return true;
}

Node *LinkedList::get(int index) {
    if (index < 0 || index >= length) {
        return nullptr;
    }
    Node *temp = head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

bool LinkedList::set(int index, int value) {
    Node* temp = get(index);
    if(temp) {
        temp->value = value;
        return true;
    }
    return false;
}

void LinkedList::reverse() {
    //Swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;

    Node* after = temp->next;
    Node* before = nullptr;

    for(int i = 0; i < length; i++) {
        //get the node after temp
        after = temp->next;

        //swap the direction of the next ptr
        temp->next = before;

        before = temp;
        temp = after;
    }
}

Node *LinkedList::findMiddleNode() {
    if(head == nullptr) {
        return head;
    }
    int middleIndex = length/2;

    Node* temp = head;

    for(int i = 0; i < middleIndex; i++) {
        temp = temp->next;
    }

    return temp;
}

bool LinkedList::hasLoop() {
    if(head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

/*
 * returns the kth node from the end of the list with out using the length
 */
Node *LinkedList::findKthFromEnd(int k) {
    int length = 0;

    Node* temp = head;

    while(temp) {
        length++;
        temp = temp->next;
    }

    if(k > length) return nullptr;

    temp = head;
    int index = length - k;
    for(int i = 0; i < index;i++) {
        temp = temp->next;
    }

    return temp;
}

/*
 * For this problem its assumed that there is no tail pointer
 * all nodes with a value less than x come before nodes with a value greater than/equal to x
 * can use length variable
 */
void LinkedList::partitionList(int x) {
    if(!head) return;

    Node* beforeStart = nullptr;
    Node* beforeEnd = nullptr;
    Node* afterStart = nullptr;
    Node* afterEnd = nullptr;
    Node* temp = head;

    while(temp) {
        Node* next = temp->next;
        temp->next = nullptr; //detaches the current node from the list

        if(temp->value < x) {
            if(!beforeStart) {
                beforeStart = temp;
                beforeEnd = temp;
            }
            else {
                beforeEnd->next = temp;
                beforeEnd = temp;
            }
        }
        else {
            if(!afterStart) {
                afterStart = temp;
                afterEnd = temp;
            }
            else {
                afterEnd->next = temp;
                afterEnd = temp;
            }
        }
        temp = next;
    }

    if(!beforeStart) {
        head = afterStart;
        return;
    }

    beforeEnd->next = afterStart;
    head = beforeStart;
}

/*
 * Leet code problem, this list will not allow you to add duplicates but for the purpose of practice lets assume otherwise
 */
void LinkedList::removeDuplicates() {
    if(length == 0) return;

    Node* temp = head;
    Node* runner = nullptr;
    Node* prev = nullptr;

    while(temp && temp->next){
        runner = temp;
        while(runner->next) {
            if(runner->next->value == temp->value) {
                //delete the duplicate
                Node* dup = runner->next;
                runner->next = runner->next->next;
                delete dup;
                length--;
            }
            else {
                runner = runner->next;
            }
        }
        temp = temp->next;
    }
}

/*
 * Each element in the list represents a 1 or 0
 * convert the binary number into a decimal
 */
int LinkedList::binaryToDecimal() {
    if(length == 0) return 0;

    int num = 0;
    Node* temp = head;
    for(int i = 0; i < length; i++) {
        num = num * 2 + temp->value;
        temp = temp->next;
    }

    return num;
}

/*
 * revers the from index m to index n
 */
void LinkedList::reverseBetween(int m, int n) {
    if(length == 0 || m < 0 || m >= length || n < m || n < 0 || n >= length) return;

    Node* temp = head;
    Node* start = nullptr;
    Node* beforeStart = nullptr;

    //Traverse to the node befor the start of the reversal
    for(int i = 0; i < m && temp; i++) {
        beforeStart = temp;
        temp = temp->next;
    }

    start = temp;

    Node* prev = nullptr;
    Node* curr = start;
    Node* next = nullptr;

    for(int i = m; i <= n && curr;i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //prev poits to the new head of reversed list
    //start points to tail of revsersed list

    if(beforeStart) {
        beforeStart->next = prev;
    }
    else {
        head = prev;
    }

    start->next = curr;
}









