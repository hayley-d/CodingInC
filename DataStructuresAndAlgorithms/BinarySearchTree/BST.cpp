//
// Created by hayley on 2024/06/22.
//

#include "BST.h"
#include <queue>
#include <iostream>

BST::BST() {
    this->root = nullptr;
}

BST::~BST() {
    destory(root);
}


bool BST::contains(int value) {
    if(!root) return false;
    Node* temp = root;
    return containsHelper(temp,value) != nullptr;
}

Node *BST::containsHelper(Node *curr,int value) {
    if(!curr) return nullptr;
    if(curr->value == value) return curr;
    if(curr->value > value) {
        return containsHelper(curr->left,value);
    }
    else {
        return containsHelper(curr->right,value);
    }
}

void BST::insert(int value) {
    if(contains(value)) return;
    if(!root) {
        this->root = new Node(value);
    }else {
        Node* temp = root;
        while(temp) {
            if(temp->value < value) {
                //go right
                if(temp->right) {
                    temp = temp->right;
                    continue;
                }
                else {
                    temp->right = new Node(value);
                    return;
                }
            }else {
                if(temp->left) {
                    temp = temp->left;
                    continue;
                }
                temp->left = new Node(value);
                return;
            }
        }
    }
}

void BST::remove(int value) {
    if(!contains) return;
    Node* temp = root;

    if(temp->value == value) {
        //update root
        if(!root->left) {
            root = root->right;
        }
        else if(!root->right) {
            root = root->left;
        }
    }

    Node* parent = getParent(root,value);

}



void BST::destory(Node *curr) {
    if(!curr) return;
    if(curr->left) destory(curr->left);
    if(curr->right) destory(curr->right);
    delete curr;
}

Node *BST::getParent(Node *curr,int value) {
    if(!curr) return nullptr;
    if(curr->left->value == value || curr->right->value == value) {
        return curr;
    }
    else if(curr->value > value) {
        //go left
        return getParent(curr->left,value);
    }
    else {
        return getParent(curr->right,value);
    }
}

Node *BST::getSmallestInSubTree(Node *curr) {
    if(!curr) return nullptr;
    if(!curr->left) return curr;
    return getSmallestInSubTree(curr->left);
}

void BST::BredthFirstSearch() {
    std::queue<Node*> myQueue;
    myQueue.push(root);

    while(myQueue.size() > 0) {
        Node* curr = myQueue.front();
        myQueue.pop();
        std::cout << curr->value << " -> ";
        if(curr->left) {
            myQueue.push(curr->left);
        }
        if(curr->right) {
            myQueue.push(curr->right);
        }
    }
}

void BST::DepthFirstSearch() {
    DFSHealper(root);
}

void BST::DFSHealper(Node *curr) {
    if(!curr) return;
    std::cout << curr->value << std::endl;
    if(curr->left) {
        DFSHealper(curr->left);
    }
    if(curr->right) {
        DFSHealper(curr->right);
    }
    return;
}








