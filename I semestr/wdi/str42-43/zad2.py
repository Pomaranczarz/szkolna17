def main():
    try:
        n = int(input("Podaj rozmiar tablicy: "))
        if n <= 0:
            print("Podano niewłaściwy rozmiar tablicy. Koniec programu.")
            exit()

        numbers = []
        for i in range(n):
            numbers.append(int(input(f'Podaj {i + 1}. liczbe: ')))

    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    last_element = numbers[-1]
    sum = 0
    count = 0
    for i in range(len(numbers) - 1):
        if numbers[i] > last_element:
            sum += numbers[i]
            count += 1

    print(f'Suma elementów większych od { last_element }: { sum }\nIch średnia: { sum / count }')

main()
