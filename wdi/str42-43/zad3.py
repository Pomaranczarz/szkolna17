# może nie najbardziej optymalne, ale za to jakie eleganckie!
def get_sum_of_digits(number):
    if number <= 0:
        return 0

    return number % 10 + get_sum_of_digits(number // 10)


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
    special_numbers = [] # liczby, których suma cyfr jest większa od ostatniej wprowadzonej
    for i in range(len(numbers) - 1):
        if get_sum_of_digits(numbers[i]) > last_element:
            special_numbers.append(numbers[i])

    print(f'Liczby, których suma cyfr jest większa od ostatniej wprowadzonej liczby: { special_numbers }')
    print(f'Ich ilość: { len(special_numbers) }')


main()
