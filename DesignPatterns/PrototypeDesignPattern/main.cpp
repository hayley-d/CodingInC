#include <iostream>
#include <string>
#include <vector>

struct Shape {
    int x;
    int y;
    std::string colour;

    Shape() : x(0), y(0), colour(""){}

    //Copy constructor
    Shape(const Shape& shape) {
        this->x = shape.x;
        this->y = shape.y;
        this->colour = shape.colour;
    }
    virtual ~Shape() = default;  // Virtual destructor
    virtual Shape* clone() = 0;
};

struct Rectangle : Shape {
    int width;
    int height;

    Rectangle(const Rectangle& rec) : Shape(rec), width(rec.width), height(rec.height) {}

    Rectangle(int x, int y, int w, int h, const std::string& colour) : Shape(), width(w), height(h) {
        this->x = x;
        this->y = y;
        this->colour = colour;
    }

    Shape* clone() override {
        return (new Rectangle(*this));
    }
};

struct Circle : Shape {
    int radius;

    Circle() : radius(0) {}

    Circle(const Circle& c): Shape(c), radius(c.radius){}

    Shape* clone() override {
        return (new Circle(*this));
    }
};

int main() {

    return 0;
}
