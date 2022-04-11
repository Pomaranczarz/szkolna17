#pragma once

#include <string>
#include <iostream>
#include <fstream>

struct Student {
    bool operator<(const Student& another)  { return points < another.points;   }
    bool operator>(const Student& another)  { return points > another.points;   }
    bool operator==(const Student& another) { return points == another.points;  }
    void save_to_csv(std::ostream& out)     { out << name << ';' << lastname << '\n'; }

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