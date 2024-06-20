//
// Created by hayley on 2024/06/20.
//

#ifndef NODE_H
#define NODE_H



class Node {
private:


public:
    int value;
    Node* next;
    Node(int v, Node* n);
    explicit Node(int value);
};



#endif //NODE_H
