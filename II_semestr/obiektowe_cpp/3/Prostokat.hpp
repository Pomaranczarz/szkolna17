#pragma once

#include <iostream>

class Rectangle
{
public:
    Rectangle(const std::string& name, double width = 1, double height = 2);
    Rectangle() = default;
    ~Rectangle();
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const double& getArea() const;
    [[nodiscard]] const double& getPerimeter() const;
    [[nodiscard]] bool setSize(double width, double height);
    [[nodiscard]] bool isValid() const;

    [[nodiscard]] std::string toString() const;
private:
    [[nodiscard]] static bool areDimensionsValid(double width, double height) {
        return width > 0 && height > 0;
    }

    [[nodiscard]] double calculateArea() const;
    [[nodiscard]] double calculatePerimeter() const;

    std::string name;
    double width;
    double height;
    bool valid;
    double area;
    double perimeter;
};