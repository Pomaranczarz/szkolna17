#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "Student.hpp"

std::pair<Student*, size_t> read_data(const char* filename);
void linear_search(Student* students, size_t size, unsigned short points);
void binary_searach(Student* students, size_t size, unsigned short points, std::ofstream& outfile);
void bubblesort(Student* students, size_t size);

int main() {
    std::pair<Student*, size_t> students = read_data("studenci.csv");
    if (!students.first) {
        std::cerr << "Blad odczytu danych\n";
        return EXIT_FAILURE;
    }

    int desired_points;
    std::cout << "Podaj liczbe szukanych punktow:\n";
    std::cin >> desired_points;

    linear_search(students.first, students.second, desired_points);

    bubblesort(students.first, students.second);
    
    std::cout << '\n';

    std::ofstream out{ "wynik.txt" };
    binary_searach(students.first, students.second, desired_points, out);
}

std::pair<Student*, size_t> read_data(const char* filename) {
    std::ifstream in{ filename };
    if (!in.good())
        return std::make_pair(nullptr, 0);

    size_t num_of_students;
    in >> num_of_students;
    in.ignore(3);

    Student* students = new Student[num_of_students];
    for (size_t i = 0; !in.eof(); ++i) {
        in >> students[i];
        std::cout << i << '\n';
    }

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

void binary_searach(Student* students, size_t size, unsigned short points, std::ofstream& outfile) {
    bool match = false;
    size_t left = 0;
    size_t right = size - 1;

    while (left <= right) {
        size_t middle = (left + right) / 2;
        if (students[middle].points == points) {
            std::cout << students[middle].name << " " << students[middle].lastname << '\n';
            students[middle].save_to_csv(outfile);
            match = true;

            int i = 1;
            while (i < right && students[middle + i].points == points) {
                std::cout << students[middle + i].name << " " << students[middle + i].lastname << '\n';
                students[middle + i].save_to_csv(outfile);
                ++i;
            }

            i = 1;
            while (i > 0 && students[middle - i].points == points) {
                std::cout << students[middle - i].name << " " << students[middle - i].lastname << '\n';
                students[middle - i].save_to_csv(outfile);
                ++i;
            }

            break;
        }
        else if (students[middle].points < points)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if (!match)
        std::cout << "Nie ma takich studentow\n";
}

void bubblesort(Student* students, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        bool swap_occured = false;
        for (size_t j = 0; j < size - 1; ++j) {
            if (students[j] > students[j + 1]) {
                std::swap(students[j], students[j + 1]);
                swap_occured = true;
            }
        }

        if (!swap_occured)
            return;
    }
}