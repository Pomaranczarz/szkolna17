def is_power_of_3(n):
    if n <= 0:
        return False
    if n % 3 == 0:
        return is_power_of_3(n // 3)
    if n == 1:
        return True
    
    return False


def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i

    return result


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def main():
    lines = []
    with open("D:\\dev\\szkolna17\\wdi\\matura2019\\liczby.txt", "r") as f:
        lines = f.readlines()
        f.close()

    numbers = []
    for line in lines:
        numbers.append(int(line))

    output = open("D:\\dev\\szkolna17\\wdi\\matura2019\\wyniki4.txt", "w", encoding="utf-8")

    # -------------------------------- sprawdzanie czy jest potęgą 3 --------------------------------
    powers_of_3 = 0
    for num in numbers:
        if is_power_of_3(int(num)):
            powers_of_3 += 1

    output.write(f'Liczb będących potęgami liczby 3: { powers_of_3 }\n')

    # --------------------------------------- suma silni cyfr ---------------------------------------
    output.write(f'Liczby, które są równe sumie silni cyfr: \n')
    for num in numbers:
        digits_factorial_sum = 0
        for c in str(num):
            digits_factorial_sum += factorial(int(c))
        
        if digits_factorial_sum == int(num):
            output.write(f'{ num }\n')

    # ----------------------------- szukanie najdłuższego ciągu nwd > 1 -----------------------------
    temp = []
    div = int(lines[0])
    first_max = 0 
    len_max = 0 
    div_max = 1
 
    for i in range(1, 500): 
        num = int(lines[i])
        nwd = gcd(div, num)
        if nwd != 1:
            if len(temp) == 0: 
                temp.append(div)

            temp.append(num) 
            div = nwd 
        else:
            if len(temp) > len_max:
                len_max = len(temp) 
                div_max = div 
                first_max = temp[0] 

            if len(temp) != 0:
                if gcd(temp[len(temp) - 1], num) > 1: 
                    a = temp[len(temp) - 1] 
                    temp.clear()
                    temp.append(a)
                    temp.append(num)
                else:
                    temp.clear()

            div = num


    output.write(f'Najdłuższy ciąg nwd > 1: { first_max } - { len_max } - { div_max }\n')

main()