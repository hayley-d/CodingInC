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
    PizzaBuilder(Base b, const std::string& cheese, const std::string& sauce, Size s) {
        root.base = b;
        root.cheese = cheese;
        root.sauce = sauce;
        root.size = s;
    }

    void addTopping(const std::string& topping) {
        root.toppings.push_back(topping);
    }

    void eat() {
        root.eatPizza();
    }
};

struct PizzaDirector {
    Pizza& makePizza(const PizzaBuilder& builder){}
    Pizza& makeDeepDishPizza(const PizzaBuilder& builder){}
    Pizza& makeCalzone(const PizzaBuilder& builder){}
    Pizza& makeDessertPizza(const PizzaBuilder& builder){}
};

int main() {
    PizzaBuilder builder(Base::normal,"Mozzarella","Tomato",Size::medium);
    builder.addTopping("Pineapple");
    builder.addTopping("Chicken");
    builder.eat();

    return 0;
}
