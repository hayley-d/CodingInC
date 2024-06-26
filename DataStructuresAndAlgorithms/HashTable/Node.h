//
// Created by hayley on 2024/06/26.
//

#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string key;
    int value;
    Node* next;

    Node(int value,std::string key);

};



#endif //NODE_H
