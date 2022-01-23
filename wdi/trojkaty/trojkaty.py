def is_triangle(a, b, c):
    return a + b > c and a + c > b and b + c > a


def get_triangle_area(a, b, c):
    s = (a + b + c) / 2
    return (s * (s - a) * (s - b) * (s - c)) ** 0.5


def get_triangle_perimeter(a, b, c):
    return a + b + c


from enum import Enum


class TriangleType(Enum):
    ACUTE = 1
    OBTUSE = 2
    RECTANGULAR = 3


def get_triangle_type(a, b, c):
    if is_pythagorean_triplet(a, b, c):
        return TriangleType.RECTANGULAR
    elif is_acute(a, b, c):
        return TriangleType.ACUTE
    else:
        return TriangleType.OBTUSE


def is_pythagorean_triplet(a, b, c):
    return a ** 2 + b ** 2 == c ** 2 or b ** 2 + c ** 2 == a ** 2 or a ** 2 + c ** 2 == b ** 2


def is_obtuse(a, b, c):
    return a ** 2 + b ** 2 > c ** 2 or b ** 2 + c ** 2 > a ** 2 or a ** 2 + c ** 2 > b ** 2


def is_acute(a, b, c):
    return a ** 2 + b ** 2 < c ** 2 or b ** 2 + c ** 2 < a ** 2 or a ** 2 + c ** 2 < b ** 2


def get_digits_sum(number):
    sum = 0
    while number > 0:
        sum += number % 10
        number //= 10

    return sum


def main():
    lines = []
    with open("D:\\dev\\szkolna17\\wdi\\trojkaty\\trojki.txt", "r") as input:   
        lines = input.readlines()

        input.close()

    lines = lines[1:]

    trinagle_count = 0
    acute_count = 0
    obtuse_count = 0
    rectangular_count = 0
    total_area = 0
    total_permieter = 0

    line_digits_sums = []

    for line in lines:
        line_num, a, b, c = [int(x) for x in line.split()]
        line_digits_sum = get_digits_sum(a)+  get_digits_sum(b) + get_digits_sum(c)
        line_digits_sums.append((line_num, line_digits_sum))

        if is_triangle(a, b, c):
            trinagle_count += 1
            triangle_type = get_triangle_type(a, b, c)
            if triangle_type == TriangleType.ACUTE:
                acute_count += 1
            elif triangle_type == TriangleType.OBTUSE:
                obtuse_count += 1
            else:
                rectangular_count += 1
            
            total_area += get_triangle_area(a, b, c)
            total_permieter += get_triangle_perimeter(a, b, c)

    output = open("D:\\dev\\szkolna17\\wdi\\trojkaty\\wynik.txt", "w", encoding="utf-8")

    output.write(f'Liczba trojkatow: { trinagle_count }\n')
    output.write(f'Liczba trojkatow prostokatnych: { rectangular_count }\n')
    output.write(f'Liczba trojkatow ostrokatnych: { obtuse_count }\n')
    output.write(f'Liczba trojkatow roznobocznych: { acute_count }\n')
    output.write(f'Suma pol powierzchni trojkatow: { total_area }\n')
    output.write(f'Suma obwodow trojkatow: { total_permieter }\n')
    output.write(f'Średnia pól powierzchni trojkatów: { total_area / trinagle_count }\n')

    output.close()

    output = open("D:\\dev\\szkolna17\\wdi\\trojkaty\\wyniki_trojki.txt", "w", encoding="utf-8")
    output.writelines(f'{ line_num } { line_digits_sum }\n' for line_num, line_digits_sum in line_digits_sums)
    

main()
