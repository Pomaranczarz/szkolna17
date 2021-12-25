from math import pi


def factorial_iter(num):
    if num == 0:
        return 1
    else:
        return num * factorial_iter(num - 1)


def newton_recur(n, k):
    if k == 0 or k == n:
        return 1
    else:
        return n/k * newton_recur(n - 1, k - 1)


def bernoulli_num(n):
    if (n - 3) % 2 == 0 and n >= 3:
        return 0

    result = 1

    for i in range(n):
        result -= newton_recur(n, i) * ((bernoulli_num(i)) / (n - i + 1))
    
    return result


def sine(angle, precision=10):
    result = 0

    for i in range(precision):
        result += (( (-1)**i ) / factorial_iter(2 * i + 1)) * angle**(2 * i + 1)

    return result 


def cosine(angle, precision=10):
    result = 0

    for i in range(precision):
        result += (( (-1)**i ) / factorial_iter(2 * i)) * angle**(2*i)

    return result
    


def tangent(angle, precision=10):
    result = 0

    for i in range(1, precision):
        result += (( bernoulli_num(2 * i) * (-1)**(i - 1) * 2**(2 * i) * (2**(2 * i) - 1) ) / factorial_iter(2 * i)) * angle**(2 * i - 1)

    return result


print(tangent(float(input()), 20))