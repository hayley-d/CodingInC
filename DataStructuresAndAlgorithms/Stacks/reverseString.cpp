//
// Created by hayley on 2024/06/22.
//

#include "reverseString.h"
/*
 * Reverses the input string str
 * uses a stack to hold characters
 * return a string
 */
string reverseString::reverseStringMethod(const std::string &str) {
    stack<char> stack;
    for(int i = 0; i < str.length();i++) {
        stack.push(str[i]);
    }

    string reverseStr = "";

    while(!stack.empty()) {
        reverseStr += stack.top();
        stack.pop();
    }

    return reverseStr;
}

/*
 * checks if the string has balanced parentheses
 */

bool reverseString::isBalancedParentheses(const string &parentheses) {
    if(parentheses.length() == 0) return true;
    stack<char> openParentheses;

    for(int i = 0; i < parentheses.length();i++) {
        if(parentheses[i] == '(') {
            openParentheses.push(parentheses[i]);
        }
        else if(parentheses[i] == ')') {
            if(openParentheses.empty()) return false;
            openParentheses.pop();
        }
    }
    return openParentheses.empty() == true;
}

/*
 * sort a stack in ascending order using 2 stacks
 */
void reverseString::sortStack(stack<int> &inputStack) {
    if(inputStack.size() < 2 || inputStack.empty()) return;

    stack<int> secondStack = stack<int>();
    int temp = -1;

    while(!inputStack.empty()) {
        temp = inputStack.top();
        inputStack.pop();

        while(!secondStack.empty() && secondStack.top() > temp) {
            inputStack.push(secondStack.top());
            secondStack.pop();
        }

        secondStack.push(temp);
    }

    while(!secondStack.empty()) {
        inputStack.push(secondStack.top());
        secondStack.pop();
    }
}


/*
 * 5
 */

/*
 * 5
 * 2
 * 1
 */


