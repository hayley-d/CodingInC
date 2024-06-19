#include <iostream>

#include "Cookie.h"
#include "Student.h"

using namespace std; //VERY IMPORTANT LINE

int main() {

    int num1 = 11; //11
    int num2 = num1; //11

    cout << "num1 = " << num1 << endl; // 11
    cout << "num2 = " << num2 << endl; // 11

    num1 = 11;
    num2 = num1;

    num1 = 22;

    cout << "num1 = " << num1 << endl; // 22
    cout << "num2 = " << num2 << endl; // 11

    int* ptr1 = new int(11); //creates a new memeory location for 11
    int* ptr2 = ptr1; //Passing reference, now ptr2 points to the same location in memeory

    cout << "ptr1 = " << ptr1 << endl; // some memory address (you need to dereference)
    cout << "ptr2 = " << ptr2 << endl; // some memory address

    cout << "ptr1 = " << *ptr1 << endl; // 11 (dereferenced ptr)
    cout << "ptr2 = " << *ptr2 << endl; // 11

    *ptr1 = 22;

    cout << "ptr1 = " << *ptr1 << endl; // 22 (dereferenced ptr)
    cout << "ptr2 = " << *ptr2 << endl; // 22

    //Declared new cookie object pointer
    Cookie* cookie1 = new Cookie("Matcha",1.45);
    cookie1->bake();

    Student* student = new Student("Hayley","Dodkins",22,"Computer Science");
    std::cout << "Student Number: " << student->getStudentNumber() << std::endl;
    std::cout << "Student Name: " << student->getName() << std::endl;
    std::cout << "Student Degree: " << student->getDegree() << std::endl;

    return 0;
}
