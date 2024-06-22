//
// Created by hayley on 2024/06/22.
//

#ifndef VECTORSTACK_H
#define VECTORSTACK_H
#include <vector>


class vectorStack {
private:
    std::vector<int> stack;

public:

    vectorStack();

    std::vector<int>& getStack();

    void printStack();

    bool isEmpty();

    int peek();

    void push(int value);

    int pop();
};



#endif //VECTORSTACK_H
