//
// Created by hayley on 2024/06/19.
//

#include "Solution.h"

/*
 * Given an array calcualte the running sum of the array
 */
std::vector<int> Solution::runningSum(std::vector<int> &nums) {
    int runningSum = 0;
    for(int i = 0; i < nums.size();i++)
    {
        nums[i] += runningSum;
        runningSum = nums[i];
    }
    return nums;
}

/*
 * given an mxn matrix accounts[i][j] is the amount of money for the ith customer in the jth bank
 * return the wealth of the customer with the most money over all the banks
 */
int Solution::maximumWealth(std::vector<std::vector<int> > &accounts)
{
    int maxWealth = 0;
    for(int i = 0; i < accounts.size();i++) {
        //Get the customer
        int totalMoney = 0;
        for(int j = 0; j < accounts[i].size();j++) {
            //for each bank add the money
            totalMoney += accounts[i][j];
        }
        if(totalMoney > maxWealth) {
            maxWealth = totalMoney;
        }
    }
    return maxWealth;
}

/*
 * Given an int n return a string array where
 * andswer[i] == FizzBuzz if i is divisible by 3 and 5
 * answer[i] == Fizz when i is divisible by 3 not 5
 * answer[i] == Buzz when i is divisible by 5 not 3
 * answer[i] == i when i is divisible by neither 3 nor 5
 */
std::vector<std::string> Solution::fizzbuzz(int n)
{
    std::vector<std::string> answer = std::vector<std::string>(n);

    for(int i = 1; i < n+1; i++) {
        if(i%3 == 0 && i%5 == 0) {
            answer[i-1] = "FizzBuzz";
        }
        else if(i%3==0 && i%5!=0) {
            answer[i-1] = "Fizz";
        }
        else if(i%5==0 && i%3!=0) {
            answer[i-1] = "Buzz";
        }
        else {
            answer[i-1] = std::to_string(i);
        }
    }

    return answer;
}

