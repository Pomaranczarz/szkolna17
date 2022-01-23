def main():
    try:
        n = int(input("Podaj n: "))
        while n < 4:
            n =  int(input("n musi być co najmniej równe 4. Podaj prawidłową wartość: "))
            
        numbers = []

        for i in range(n):
            numbers.append(int(input(f'Podaj { i + 1}. liczbe: ')))
            
    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    max_sum = 0;
    index = []
    for i in range(1, len(numbers) - 1):
        current_sum = numbers[i - 1] + numbers[i] + numbers[i + 1]
        if current_sum > max_sum:
            max_sum = current_sum
            index = [i - 1, i, i + 1]

    print(f'Największa suma: { max_sum }\nIndeksy tych elementów: { index }')


main()
