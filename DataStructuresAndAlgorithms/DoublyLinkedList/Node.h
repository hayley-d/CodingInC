//
// Created by hayley on 2024/06/21.
//

#ifndef NODE_H
#define NODE_H



class Node {
public:
    int value;
    Node* next;
    Node* prev;

    explicit Node(int value);
};



#endif //NODE_H
