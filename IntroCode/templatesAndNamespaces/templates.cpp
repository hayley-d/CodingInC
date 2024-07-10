//
// Created by User-PC on 10/07/2024.
//
#include <iostream>
#include <vector>
#include <string>

    template<typename T>
    void print(T value){
        std::cout << value << std::endl;
    }

    template<typename T,int N>
    class Array{
        T m_Array[N]
    public:
        int getSize() const {return N;}
    };

    int main{

        Array<double,5> array;

        print<std::string>("Hayley");
        print<int>(22);
        print<float>(17.77777777777);
        print<char>('h');



        return 0;
    };

