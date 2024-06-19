//
// Created by hayley on 2024/06/19.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    //Variables
    std::string studentNumber;
    std::string firstName;
    std::string lastName;
    int age;
    double gpa;
    std::string degree;

    //Private functions
    std::string generateStudentNumber();

public:
    Student(); //Default constructor
    Student(std::string firstName,std::string lastName,int age,std::string degree);

    ~Student(); //Deconstructor

    //Getters
    std::string getStudentNumber();
    std::string getName();
    std::string getDegree();
    int getAge();
    double getGpa();

    //Setters
    void setGpa(double gpa);
    void setAge(int age);
    void setDegree(std::string degree);







};



#endif //STUDENT_H
