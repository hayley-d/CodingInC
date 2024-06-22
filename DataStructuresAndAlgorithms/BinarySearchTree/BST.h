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
    BST(int value);
    ~BST();


private:
    void destory(Node* curr);
};



#endif //BST_H
