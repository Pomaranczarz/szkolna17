def main():
    try:
        n = int(input("Podaj n: "))
        if n <= 0: # nothing to check
            exit()
            
        numbers = []

        for i in range(n):
            numbers.append(int(input(f'Podaj { i + 1}. liczbe: ')))
            
    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    max = max2 = int()

    for elem in numbers:
        if elem > max:
            max2 = max
            max = elem
        elif elem > max2 and elem != max:
            max2 = elem

    print(max, max2)


main()
