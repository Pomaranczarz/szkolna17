from math import sin, pi

def trapeze_area(a, b, h):
    return ((a + b) / 2) * h


def area():
    range_begin = 0.0
    range_end = pi

    sub_trapeze_size = 0.00001
    area = 0

    while range_begin < range_end:
        area += trapeze_area(sin(range_begin), sin(range_begin + sub_trapeze_size), sub_trapeze_size)
        range_begin += sub_trapeze_size


    return area


print(area())