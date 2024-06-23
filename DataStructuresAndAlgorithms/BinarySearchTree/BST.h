//
// Created by hayley on 2024/06/22.
//

#ifndef BST_H
#define BST_H

#include "Node.h"

class BST {
public:
    Node* root;

    BST();
    ~BST();

    bool contains(int value);
    void insert(int value);
    void remove(int value);
    void DepthFirstSearch();
    void BredthFirstSearch();


private:
    void destory(Node* curr);
    Node* containsHelper(Node* curr,int value);
    Node* getParent(Node* curr,int value);
    Node* getSmallestInSubTree(Node* curr);
};



#endif //BST_H
