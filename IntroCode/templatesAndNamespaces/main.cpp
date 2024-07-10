#include <iostream>
#include<vector>

int main() {

    std::string str1 = "Hello"; //infers string
    auto age = 13; //infers int

    std::string::reverse_iterator rit;
    for(rit = str1.rbegin(); rit != str1.rend(); rit++){
        std::cout << *rit << std::endl;
    }

    std::vector<int> vec = {1,2,3,4,5};
    std::vector<int>::iterator it = vec.begin();

    //Increment the iterator (moves to the next location in memory)

    std::cout << *it << std::endl; // 1
    it++;
    std::cout << *it << std::endl; // 2


    std::cout << *it << std::endl; // 2
    it+=2;
    std::cout << *it << std::endl; // 4

    //Decrment the iterator (move it back a location in memory
    it--;
    std::cout << *it << std::endl; // 4
    std::cout << *it << std::endl; // 3

    std::cout << *it << std::endl; // 3
    it-=2;
    std::cout << *it << std::endl; // 1

    //Number of elements between iterators
    std::vector<int>::iterator it1 = vec.begin();
    std::vector<int>::iterator it2 = vec.end();

    std::cout << std::distance(it1,it2) << std::endl;


    Pair<int> intPair(1,2);
    std::cout << intPair.getFirst() << std::endl;

    Pair<int>* pair = new Pair(1,2);
    std::cout << pair->getFirst() << std::endl;





    std::cout << "Hello, World!" << std::endl;
    return 0;
}
