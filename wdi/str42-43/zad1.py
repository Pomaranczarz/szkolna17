def main():
    print("Podane liczby ujemnej kończy wczytywanie, natomiast wpisanie zera przełącza tryb liczenia średniej")
    
    try:
        if_loop = True
        if_count_average = False
        sum = 0
        count = 0
        while if_loop:
            userInput = int(input("Podaj liczbe: "))
            if userInput < 0 and not if_count_average:
                if_loop = False
            elif userInput == 0:
                if_count_average = not if_count_average
            elif if_count_average:
                sum += userInput
                count += 1

    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    print(f'Średnia: { sum / count }');
main()