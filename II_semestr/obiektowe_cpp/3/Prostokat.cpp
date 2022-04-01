#include "Prostokat.hpp"

Rectangle::Rectangle(const std::string& name, double width, double height)
    : name { name }
{
    if (areDimensionsValid(width, height))
    {
        this->width = width;
        this->height = height;
        this->valid = true;
        this->area = calculateArea();
        this->perimeter = calculatePerimeter();
    }
    else
    {
        this->valid = false;
        this->width = this->height = this->area = this->perimeter = 0;
    }
}

Rectangle::~Rectangle() {
    std::cout << "Prostokat: " << name << " znika.\n";
}

const std::string& Rectangle::getName() const {
    return name;
}

const double& Rectangle::getArea() const {
    return area;
}

const double& Rectangle::getPerimeter() const {
    return perimeter;
}

bool Rectangle::isValid() const {
    return valid;
}

bool Rectangle::setSize(double width, double height) {
    if (Rectangle::areDimensionsValid(width, height)) {
        valid = true;
        this->width = width;
        this->height = height;
        area = calculateArea();
        perimeter = calculatePerimeter();
        return true;
    }
    return false;
}

double Rectangle::calculateArea() const {
    return width * height;
}

double Rectangle::calculatePerimeter() const {
    return 2 * (width + height);
}

std::string Rectangle::toString() const {
    std::string result {};
    result += "Prostokat o nazwie: " + name + " ma wymiary: " + std::to_string(width) + "x" + std::to_string(height);
    if (valid)
        result += " obwod: " + std::to_string(perimeter) + " pole: " + std::to_string(area);
    else
        result += " niepoprawne wymiary";

    return result;
}

