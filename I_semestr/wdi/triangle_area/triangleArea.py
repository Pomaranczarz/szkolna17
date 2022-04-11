from math import sqrt

def main():
    a = float(input("Podaj a:"))
    b = float(input("Podaj b:"))
    c = float(input("Podaj c:"))

    if not((a + b > c) and (a + c > b) and (b + c > a)):
        print("Z podanych boków nie można utworzyć trójkąta")
        return -1

    p = 0.5 * (a + b + c)
    area = sqrt(p * (p - a) * (p - b) * (p - c))
    print('Pole trójkąta o bokach: {} x {} x {} wynosi: {}'.format(a, b, c, area))

main()