from math import sqrt

def main():
    a = float(input("Podaj a:"))
    b = float(input("Podaj b:"))
    c = float(input("Podaj c:"))

    if a == 0:
        print("To nie jest równanie kwadratowe")
        return -1

    delta = b * b - 4 * a * c
    if delta < 0:
        print("Równanie nie ma pierwiastków")
        return 0
    elif delta == 0:
        root = ((-1) * b - sqrt(delta)) / (2 * a)
        print("Równanie ma jeden pierwiastek: " + str(root))
    else:
        root1 = ((-1) * b - sqrt(delta)) / (2 * a)
        root2 = ((-1) * b + sqrt(delta)) / (2 * a)
        print("Równanie ma dwa pierwiastki: " + str(root1) + ", " + str(root2))

main()