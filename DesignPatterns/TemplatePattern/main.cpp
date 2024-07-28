#include <iostream>

class GameAI {
    int pos;
public:
    void takeTurn() {
        collectResources();
        buildStructures();
        buildUnits();
        attack();
    }

    void collectResources() {
        //some implementation
    }

    virtual void buildStructures() {
        //some implementation
    }

    virtual void buildUnits() {
        //some implemenetation
    }

    void attack() {
        //some implementation
    }

    virtual void sendScouts(int pos)= 0;

    virtual void sendWarriors(int pos) = 0;

    virtual ~GameAI();
};

class SlothAI : public GameAI{
public:
    void buildStructures() override {
        //some implementation
    }

    void sendScouts(int pos) override {
        //some implementation
    }

    void sendWarriors(int pos) override {
        //some implementation
    }
};

class NookAI : public GameAI{
public:
    void buildUnits() override {
        //some implementation
    }

    void sendScouts(int pos) override {
        //some implementation
    }

    void sendWarriors(int pos) override {
        //some implementation
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
