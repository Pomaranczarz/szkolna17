#include <iostream>
#include <fstream>

#include "functions.hpp"
#include "Student.hpp"

bool got10OrLessPoints(const Student& student)   { return student.points <= 10;         }
bool pointsDivisibleBy3(const Student& student)  { return student.points % 3 == 0;      }
bool pointsDivBy3RemIs2(const Student& student)  { return student.points % 3 == 2;      }
void printStudents(Student* students, size_t begin, size_t end);

int main() {
    std::ifstream input{ "studenci.csv" };
    if (input.good()) {
        size_t students_count;
        input >> students_count;
        input.ignore(3);

        Student* students = new Student[students_count];

        for (size_t i = 0; i < students_count && !input.eof(); ++i)
            input >> students[i];

        std::cout << "Przed podzialem: \n";
        printStudents(students, 0, students_count);

        size_t second_subset_first_index = to_two_subsets(students, students_count, got10OrLessPoints);

        std::cout << "Studenci, ktorzy otrzymali co najwyzej 10 pkt:\n";
        printStudents(students, 0, second_subset_first_index);
        std::cout << "Studenci, ktorzy otrzymali wiecej niz 10 pkt:\n";
        printStudents(students, second_subset_first_index, students_count);

        ThreeSubsetsSortResult sort_result = to_three_subsets(students, students_count, pointsDivisibleBy3, pointsDivBy3RemIs2);

        std::cout << "Studenci, ktorych liczba punktow jest podzielna przez 3:\n";
        printStudents(students, 0, sort_result.first_set_end_index + 1);
        std::cout << "Studenci, ktorych liczba punktow przy dzieleniu przez 3 daje 1:\n";
        printStudents(students, sort_result.first_set_end_index + 1, sort_result.third_set_start_index);
        std::cout << "Studenci, ktorych liczba punktow przy dzieleniu przez 3 daje 2:\n";
        printStudents(students, sort_result.third_set_start_index, students_count);

        delete[] students;
    } 
    else {
        std::cerr << "Blad pliku\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void printStudents(Student* students, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i)
        std::cout << students[i] << '\n';
}
