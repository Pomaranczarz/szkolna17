def main():
    try:
        userInput = int(input("Podaj liczbę (wpisanie 0 zakończy wpisywanie): "))
        numbers = []

        while userInput != 0:
            numbers.append(userInput)
            userInput = int(input("Podaj liczbę (wpisanie 0 zakończy wpisywanie): "))

    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    if len(numbers) <= 0:
        print("Za mało elementów")
    else:
        for i in range(len(numbers)):
            if numbers[i] != numbers[len(numbers) - 1 - i]:
                print("Nie jest symetryczna")
                return

        print("Jest symetryczna")

main()
