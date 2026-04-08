// Day 22: Inheritance and Dynamic Polymorphism
// Compile: g++ -std=c++20 -Wall -Wextra polymorphism.cpp -o polymorphism

#include <iostream>
#include <vector>
#include <memory>
#include <numbers>

// Abstract Base Class (Interface)
class Shape {
public:
    // Virtual destructor is ESSENTIAL for safe polymorphic deletion!
    virtual ~Shape() = default;

    // Pure virtual functions (must be implemented by derived classes)
    virtual double area() const = 0;
    virtual void describe() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return 3.1415926535 * radius * radius;
    }

    void describe() const override {
        std::cout << "Circle (radius: " << radius << ", area: " << area() << ")\n";
    }
};

class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void describe() const override {
        std::cout << "Rectangle (" << width << "x" << height << ", area: " << area() << ")\n";
    }
};

int main() {
    std::cout << "=== Day 22: Inheritance & Polymorphism ===\n\n";

    // Polymorphic collection using std::unique_ptr<Shape>
    std::vector<std::unique_ptr<Shape>> canvas;
    canvas.push_back(std::make_unique<Circle>(5.0));
    canvas.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    canvas.push_back(std::make_unique<Circle>(2.5));

    std::cout << "--- Canvas Inspection ---\n";
    double total_area = 0.0;
    for (const auto& shape : canvas) {
        shape->describe(); // Dynamic dispatch via vtable!
        total_area += shape->area();
    }

    std::cout << "\nTotal Canvas Area: " << total_area << "\n";
    return 0;
}
