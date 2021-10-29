def binToDec(binaryNumber):
    result = 0
    for i in range(0, len(binaryNumber)):
        result += (ord(binaryNumber[::-1][i]) - ord('0')) * 2**i

    return result

print(binToDec("1111"))
print(binToDec("1010"))
print(binToDec("0"))
print(binToDec("11111111"))