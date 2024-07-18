#include <iostream>
#include <vector>
#include <string>

enum Base {
    sourdough,
    stuffedCrust,
    lowCarb,
    normal
};

enum Size {
    small,
    medium,
    large
};

struct Pizza {
    std::vector<std::string> toppings;
    Base base;
    std::string cheese;
    std::string sauce;
    Size size;
    int slices;

    Pizza() {
        slices = 8;
    }

    void eatPizza() {
        if(slices > 0) {
            std::cout << "Nom Nom Nom" << std::endl;
            slices--;
        }
    }

};

struct PizzaBuilder {
    //create the root elemnt
    Pizza root;

    //create the constructor
    /*PizzaBuilder(Base b, const std::string& cheese, const std::string& sauce, Size s) {
        root.base = b;
        root.cheese = cheese;
        root.sauce = sauce;
        root.size = s;
    }*/

    PizzaBuilder(){}

    PizzaBuilder& addBase(const Base b) {
        root.base = b;
        return *this;
    }

    PizzaBuilder& addCheese(const std::string& cheese) {
        root.cheese = cheese;
        return *this;
    }

    PizzaBuilder& addSauce(std::string sauce) {
        root.sauce = sauce;
        return *this;
    }

    PizzaBuilder& addSize(const Size s) {
        root.size = s;
        return *this;
    }

    //Fluent interface
    PizzaBuilder& addTopping(const std::string& topping) {
        root.toppings.push_back(topping);
        return *this;
    }

    void eat() {
        root.eatPizza();
    }
};

struct PizzaDirector {
private :
    PizzaBuilder builder;

public:
    PizzaDirector(PizzaBuilder& builder) : builder(builder){}

    Pizza& makeHawiaan () {
        builder.addBase(Base::sourdough);
        builder.addSauce("Tomato");
        builder.addCheese("Mozzarella");
        builder.addSize(Size::medium);
        builder.addTopping("Pineapple").addTopping("Ham");
        return builder.root;
    }

    Pizza& makeDessertPizza() {
        builder.addBase(Base::normal);
        builder.addSauce("Nutella");
        builder.addCheese("Mascapone");
        builder.addSize(Size::small);
        builder.addTopping("Biscoff Cookies").addTopping("Lindor Truffles");
        return builder.root;
    }
};

int main() {
    /*PizzaBuilder builder(Base::normal,"Mozzarella","Tomato",Size::medium);
    builder.addTopping("Pineapple");
    builder.addTopping("Chicken");
    builder.eat();*/


    PizzaBuilder builder;
    PizzaDirector director(builder);
    Pizza hawiaan = director.makeHawiaan();

    return 0;
}
