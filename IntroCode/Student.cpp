//
// Created by hayley on 2024/06/19.
//

#include "Student.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>

// Default constructor
Student::Student() : studentNumber(generateStudentNumber()), firstName(""), lastName(""), age(0), gpa(0.0), degree("") {}

// Parameterized constructor
Student::Student(std::string firstName, std::string lastName, int age, std::string degree) : firstName(firstName), lastName(lastName), age(age), gpa(0.0), degree(degree)
{
    this->studentNumber = generateStudentNumber();
}

// Destructor
Student::~Student() {
    std::cout << "Student is gone" << std::endl;
}

/**
     * @brief Generates a student number
     *
     * Uses the std::to_string function to convert the integer to its string representation.
     *
     * @return std::string The student number
     */
std::string Student::generateStudentNumber() {
    //generate a random 6 digit string and prepend a u in the front
    std::string randomString = "";
    for(int i = 0; i < 6; i++) {
        int random_number = rand() % (10);
        randomString += std::to_string(random_number);
    }

    return "u" + randomString;
}

std::string Student::getStudentNumber() {
    return this->studentNumber;
}

std::string Student::getName() {
    return this->firstName +" " + this->lastName;
}

std::string Student::getDegree() {
    return this->degree;
}

int Student::getAge() {
    return age;
}

double Student::getGpa() {
    return this->gpa;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDegree(std::string degree) {
    this->degree = degree;
}

void Student::setGpa(double gpa) {
    this->gpa = gpa;
}













