#pragma once

#include <string>
#include <iostream>
#include <fstream>

struct Student {
    std::string name;
    std::string lastname;
    unsigned points;

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        return out << "{ " << student.name << " " << student.lastname << ", " << student.points << " }";
    }

    friend std::ifstream& operator>>(std::ifstream& in, Student& student) {
        std::string temp_points;

        std::getline(in, student.name, ';');
        std::getline(in, student.lastname, ';');
        std::getline(in, temp_points);

        student.points = std::stoi(temp_points);

        return in;
    }
};
