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

    already_checked = []
    print("Więcej niż 2 razy wystąpiły: ")
    for i in range(len(numbers)):
        count = 1
        if numbers[i] in already_checked:
            continue
        else: 
            already_checked.append(numbers[i])

        for j in range(len(numbers)):
            if i != j and numbers[i] == numbers[j]:
                count += 1

        if count > 2:
            print(numbers[i])

main()
