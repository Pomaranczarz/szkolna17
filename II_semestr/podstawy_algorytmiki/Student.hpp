#pragma once

#include <string>
#include <iostream>
#include <fstream>

struct Student {
    Student() = default;
    Student(const char* name, const char* lastname, unsigned short points) 
        : name(name)
        , lastname(lastname)
        , points(points)
    {

    }

    Student(const std::string& name, const std::string& lastname, unsigned short points)
        : name{ name }
        , lastname{ lastname }
        , points{ points }
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        return out << "{ " << student.name << ", " << student.lastname << " [" << student.points << "] }";
    }

    friend std::istream& operator>>(std::istream& in, Student& student) {
        std::getline(in, student.name, ';');
        std::getline(in, student.lastname, ';');

        std::string temp_points;
        std::getline(in, temp_points);
        student.points = std::stoi(temp_points);
    }

    std::string name;
    std::string lastname;
    unsigned short points;
};