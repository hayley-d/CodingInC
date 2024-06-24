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
    Node* parent = getParent(root,value);

    if(!parent) {
        if(root->value == value) {
            //update root
            if(!root->left) {
                root = root->right;
            }
            else if(!root->right) {
                root = root->left;
            }else {
                Node* leftNode = root->left;
                root = root->right;
                Node* smallestNode = getSmallestInSubTree(root);
                smallestNode->left = leftNode;
            }
            delete temp;
            return;
        }
        return;
    }
    else if(parent->left->value != value || parent->right->value != value) return;


    if(parent->left->value == value) {
        Node* nodeToDelete = parent->left;

        if(!nodeToDelete->left){
            parent->left = nodeToDelete->right;
        }
        else if(!nodeToDelete->right) {
            parent->left = nodeToDelete->left;
        }
        else {
            Node* smallestNode = getSmallestInSubTree(nodeToDelete->right);
            smallestNode->left = nodeToDelete->left;
            parent->left = nodeToDelete->right;
        }
        delete nodeToDelete;
    }
    else {
        Node* nodeToDelete = parent->right;

        if(!nodeToDelete->left){
            parent->right = nodeToDelete->right;
        }
        else if(!nodeToDelete->right) {
            parent->right = nodeToDelete->left;
        }
        else {
            Node* smallestNode = getSmallestInSubTree(nodeToDelete->right);
            smallestNode->left = nodeToDelete->left;
            parent->right = nodeToDelete->right;
        }
        delete nodeToDelete;
    }
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

void BST::deleteNode(int value) {
    if(!contains(value)) return;

    root = deleteHelper(root,value);
}

Node *BST::deleteHelper(Node *curr, int value) {
    if(!curr) return nullptr;
    if(value < curr->value) {
        curr->left = deleteHelper(curr->left,value);
    }
    else if(value > curr->value) {
        curr->right = deleteHelper(curr->right,value);
    }
    else if(value == curr->value) {
        if(!curr->left && !curr->right) {
            delete curr;
            return nullptr;
        }
        else if(curr->left && !curr->right) {
            Node* temp = curr->left;
            delete curr;
            return temp;
        }
        else if(!curr->left && curr->right) {
            Node* temp = curr->right;
            delete curr;
            return temp;
        }
        else {
            //has both children
            Node* min = getSmallestInSubTree(curr->right);
            Node* temp = curr->left;
            min->left = temp;
            delete curr;
            return min;
        }
    }

    return curr;
}










