from random import randint


def get_random_unique_array(number_of_elements):
    result = []
    for i in range(number_of_elements):
        random_number = randint(1, 40)
        while random_number in result:
            random_number = randint(1, 40)

        result.append(random_number)

    return result


def count_similar_numbers(randomized_array, guess_array):
    count = 0
    for element in guess_array:
        count += 1 if element in randomized_array else 0

    return count


def main():
    try: 
        userNumbers = []

        for i in range(6):
            userInput = int(input(f'Podaj { i + 1 }. liczbe z zakresu 1-40: '))
            while userInput in userNumbers:
                userInput = int(input(
                    f'Liczby muszą być różne! Ponownie podaj { i + 1 }. liczbe z zakresu 1-40: '
                ))

            userNumbers.append(userInput)
            
    except ValueError:
        print("Podano nieprawidlowa wartosc dla typu 'int'. Koniec programu.")
        exit()

    random_numbers = get_random_unique_array(6)
    guessed_numbers = count_similar_numbers(random_numbers, userNumbers)

    if guessed_numbers == 6:
        print("Wygrałeś 2000 zł")
    elif guessed_numbers == 5:
        print("Wygrałeś 400 zł")
    elif guessed_numbers == 4:
        print("Wygrałeś 50 zł")
    else:
        print("Nic nie wygrałeś")
    

main()
