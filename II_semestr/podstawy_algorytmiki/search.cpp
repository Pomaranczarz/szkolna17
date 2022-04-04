#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "Student.hpp"

std::pair<Student*, size_t> read_data(const char* filename) {
    std::ifstream in{ filename };
    if (!in.good()) {
        std::cerr << "Blad pliku\n";
        return std::make_pair(nullptr, 0);
    }

    size_t num_of_students;
    in >> num_of_students;
    in.ignore(3);

    Student* students = new Student[num_of_students];
    for (size_t i = 0; !in.eof(); ++i)
        in >> students[i];

    return std::make_pair(students, num_of_students);
}

void linear_search(Student* students, size_t size, unsigned short points) {
    bool match = false;

    for (size_t i = 0; i < size; ++i) {
        if (students[i].points == points) {
            std::cout << students[i].name << " " << students[i].lastname << '\n';
            match = true;
        }
    }

    if (!match) 
        std::cout << "Nie ma takich studentow\n";
}

int main() {
    auto students = read_data("studenci.csv");
    if (!students.first)
        return EXIT_FAILURE;

    linear_search(students.first, students.second, 5);
}