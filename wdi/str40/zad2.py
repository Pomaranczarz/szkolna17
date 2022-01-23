def main():
    try:
        n = int(input("Podaj n: "))
        if n <= 0: # nothing to check
            exit()

        numbers = []
        
        for i in range(n):
            numbers.append(int(input(f'Podaj { i + 1}. liczbe: ')))

        begin = int(input("Podaj dolną granicę: "))
        end = int(input("Podaj górną granicę: "))
        
    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    elems_in_range = 0
    for elem in numbers:
        elems_in_range += 1 if elem in range(begin, end + 1) else 0

    print(f'Elementów znajdujących się w zakresie: { elems_in_range }')


main()
