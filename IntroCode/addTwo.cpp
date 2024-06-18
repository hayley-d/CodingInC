//
// Created by User-PC on 18/06/2024.
//

#include <iostream>
#include <vector>
#include <string>

#include "addTwo.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        //get the first number
        int num1 = 0;

        //Get the list size
        int listSize1 = 0;

        ListNode* ptr = l1;

        while(ptr != nullptr)
        {
            listSize1++;
            ptr = ptr->next;
        }

        //Create array to store the number
        std::vector<int> arr(listSize1);

        //reset the pointer
        ptr = l1;

        //populate the array
        int counter = 0;
        while(ptr != nullptr)
        {
            arr[counter] = ptr->val;
            ptr = ptr->next;
            counter++;
        }

        //make number
        std::string num1Str = "";

        for(int i = arr.size()-1; i >= 0; i--)
        {
            num1Str += std::to_string(arr[i]);
        }

        //convert number into a int
        num1 = std::stoi(num1Str);

        //Do the same with num2
        //get the first number
        int num2 = 0;

        //Get the list size
        int listSize2 = 0;

        ptr = l2;
        while(ptr != nullptr)
        {
            listSize2++;
            ptr = ptr->next;
        }

        //Create array to store the number
        std::vector<int> arr2(listSize2);

        //reset the pointer
        ptr = l2;

        //populate the array
        counter = 0;
        while(ptr != nullptr)
        {
            arr2[counter] = ptr->val;
            ptr = ptr->next;
            counter++;
        }

        //make number
        std::string num2Str = "";
        for(int i = arr2.size()-1; i >= 0; i--)
        {
            num2Str += std::to_string(arr2[i]);
        }

        //convert number into a int
        num2 = std::stoi(num2Str);

        //Add the numbers
        int resultNum = num1 + num2;

        std::string resultStr = std::to_string(resultNum);

        ListNode* resHead = new ListNode(0);
        ListNode* current = resHead;

        for (int i = resultStr.size() - 1; i >= 0; --i) {
            current->next = new ListNode(resultStr[i] - '0');
            current = current->next;
        }

        return resHead->next;

    }
};
