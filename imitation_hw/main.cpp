#include <iostream>
#include <string>
#include <vector>


class IShape {
public:
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0; 
    virtual ~IShape() {}
};


class Color {
private:
    std::string color;
public:
    Color(const std::string& color) : color(color) {}
    std::string getColor() const { return color; }
};


class Circle : public IShape {
private:
    double radius;
    Color color; 
public:
    Circle(double radius, const std::string& color) : radius(radius), color(color) {}
    void draw() const override {
        std::cout << "Drawing a " << color.getColor() << " circle with radius " << radius << "\n";
    }
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};


class Rectangle : public IShape {
private:
    double width, height;
    Color color; 
public:
    Rectangle(double width, double height, const std::string& color)
        : width(width), height(height), color(color) {}
    void draw() const override {
        std::cout << "Drawing a " << color.getColor() << " rectangle with width " << width
            << " and height " << height << "\n";
    }
    double calculateArea() const override {
        return width * height;
    }
};


class ColoredShape : public IShape, public Color {
private:
    IShape& shape; 
public:
    ColoredShape(IShape& shape, const std::string& color)
        : Color(color), shape(shape) {}
    void draw() const override {
        std::cout << "Adding color: " << getColor() << "\n";
        shape.draw();
    }
    double calculateArea() const override {
        return shape.calculateArea();
    }
};


int main() {
    Circle circle(5.0, "red");
    Rectangle rectangle(4.0, 6.0, "blue");
    ColoredShape coloredCircle(circle, "green");

    std::vector<IShape*> shapes = { &circle, &rectangle, &coloredCircle };

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->calculateArea() << "\n";
    }

    return 0;
}
