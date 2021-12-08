def factorial_recur(num):
    return 1 if num == 0 else num * factorial_recur(num - 1)


def factorial_iter(num):
    result = 1
    for i in range(2, num + 1):
        result *= i

    return result