//
// Created by hayley on 2024/06/22.
//

#ifndef REVERSESTRING_H
#define REVERSESTRING_H

#include <string>
#include <stack>

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack'

class reverseString {
public:
    string reverseStringMethod(const string& str);
    bool isBalancedParentheses(const string& parentheses);
    void sortStack(stack<int>& inputStack);
};



#endif //REVERSESTRING_H
