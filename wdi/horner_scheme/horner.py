def horner(num): # dla n - bitowej notacji uzupelnieniowej
    w = (-1) * int(num[0])
    for i in range(1, len(num)):
        w = 2 * w + int(num[i])

    return w

def horner_1(num): # dla dowolnej binarnej
    w = int(num[0])
    for i in range(1, len(num)):
        w = w * 2 + int(num[i])

    return w

print(horner_1("101001"))