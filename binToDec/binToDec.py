def binToDec(binaryNumber):
    result = 0
    for i in range(0, len(binaryNumber)):
        result += (ord(binaryNumber[::-1][i]) - ord('0')) * 2**i

    return result