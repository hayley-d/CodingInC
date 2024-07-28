#include <iostream>

class State {
    int num1;
    int num2;
    int claculatedValue;
public:
    State(const int num1, const int num2, const int calculatedValue) : num1(num1), num2(num2), claculatedValue(calculatedValue){}
    int getNum1() const {return num1;}
    int getNum2() const {return num2;}
    int getCalculated() const {return claculatedValue;}
};

class Calculator;

class Memento {
private:
    friend Calculator;

    State* state;

    Memento(int num1,int num2, int calculatedValue) {
        state = new State(num1,num2,calculatedValue);
    }

public:
    virtual ~Memento() {
        delete state;
    }
};

class Calculator {
    int calculatedValue;
    int num1;
    int num2;
public:
    Calculator() : calculatedValue(0) ,num1(0), num2(0){}
    Calculator(const int num1, const int num2) : calculatedValue(0), num1(num1), num2(num2){}

    int add() {
        calculatedValue = num1+num2;
        return calculatedValue;
    }
    int multiply() {
        calculatedValue = num1 * num2;
        return calculatedValue;
    }
    int subtract() {
        calculatedValue = num1 - num2;
        return calculatedValue;
    }
    int divide() {
        calculatedValue = num1/num2;
        return calculatedValue;
    }
    int getNum1() {
        return num1;
    }
    int getNum2() {
        return num2;
    }
    int getCalculatedValue() {
        return calculatedValue;
    }
    void print() {
        std::cout << num1 << std::endl;
        std::cout << num2 << std::endl;
        std::cout << "Calculated: " << calculatedValue << std::endl;
    }

    int ans()
    {
        num1 = 0;
        num2 = 0;
        int temp = calculatedValue;
        calculatedValue = 0;
        return temp;
    }

    Memento* createMemento() {
        return new Memento(num1,num2,calculatedValue);
    }

    void restore(const Memento& memento) {
        State* s  = memento.state;
        num1 = s->getNum1();
        num2 = s->getNum2();
        calculatedValue = s->getCalculated();
    }
};

class Caretaker {
    Memento* memento;
public:
    void storeMemento(Memento* mem) {
        memento = mem;
    }
    Memento* retrieveMemento() {
        return memento;
    }

    ~Caretaker() {
        delete memento;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
