#include <iostream>

class Shape{
private:

public:
    virtual void draw() const = 0;

    virtual double calculateArea() const = 0;

    void displayArea() const{
        std::cout << "Area: " << calculateArea() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
}

    double calculateArea() const override{
        return 3.14 * radius * radius;
}
};

class Rectangle : public Shape{
private:
    double side_1, side_2;
public:
    Rectangle(double a, double b) : side_1(a), side_2(b) {}

    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }

    double calculateArea() const override{
        return side_1 * side_2;
    }
};

class Triangle : public Shape{
private:
    double side, height;
public:
    Triangle(double a, double h) : side(a), height(h) {}

    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;
    }

    double calculateArea() const override{
        return 0.5 * side * height;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4,5);
    Triangle triangle(3,4);

    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;
    Shape* shape3 = &triangle;

    shape1 -> draw();
    shape2 -> draw();
    shape3 -> draw();

    shape1->displayArea();
    shape2->displayArea();
    shape3->displayArea();

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}

