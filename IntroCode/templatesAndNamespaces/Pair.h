//
// Created by User-PC on 10/07/2024.
//

#ifndef LEETCODE_PAIR_H
#define LEETCODE_PAIR_H

template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T a, T b);
    T getFirst();
    T getSecond();
    void setFirst(T f);
    void setSecond(T s);
};


#endif //LEETCODE_PAIR_H
