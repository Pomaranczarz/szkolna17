def sqrt(n, epsilon):
    if n < 0:
        raise ValueError("Nie można obliczyć pierwiastka drugiego stopnia z liczby ujemnej")

    a = 1
    b = n
    while abs(a - b) >= epsilon:
        a = (a + b) / 2
        b = n / a 

    return a

print(sqrt(float(input("Podaj liczbe: \n")), 0.00000001))