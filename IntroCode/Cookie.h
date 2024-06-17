//
// Created by hayley on 2024/06/17.
//

#ifndef COOKIE_H
#define COOKIE_H

#include <string>

class Cookie {

private:
    std::string flavor;
    double weight; // in grams

public:
    // Constructors
    Cookie(); // Default constructor
    Cookie(const std::string& flavor, double weight);

    // Destructor
    ~Cookie();

    // Member functions
    void setFlavor(const std::string& flavor);
    void setWeight(double weight);
    void bake();
    void eat();

    // Getter functions
    std::string getFlavor() const;
    double getWeight() const;
};


#endif //COOKIE_H
