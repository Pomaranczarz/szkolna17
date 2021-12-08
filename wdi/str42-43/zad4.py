# Pobierać  od  użytkownika  liczby  do  momentu  wpisania  liczby  zero,  bądź  pobrania 
# dziesięciu  wartości.  Po  zakończonym  wczytywaniu  ustawić  liczby  tak,  aby  liczby 
# parzyste znalazły się po jednej stronie tablicy, a nieparzyste po drugiej. Wyświetlić 
# zawartość tablicy. 

def main():
    try:
        count = 1
        even_numbers = []
        odd_numbers = []
        userInput = int(input("Podaj liczbe: (wpisanie liczby 0 lub podanie 10 elementów zakończy wczytywanie)"))
        
        if userInput == 0:
            return
        while count != 10 and userInput != 0:
            even_numbers.append(userInput) if userInput % 2 == 0 else odd_numbers.append(userInput)
            userInput = int(input("Podaj liczbe: (wpisanie liczby 0 lub podanie 10 elementów zakończy wczytywanie)"))

    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    numbers = odd_numbers + even_numbers
    print(numbers)

main()
