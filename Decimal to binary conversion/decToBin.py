def decToBin(decNumber):
    result = ""
    while decNumber > 0:
        result += chr(decNumber % 2 + ord('0'))
        decNumber = int(decNumber / 2)

    return result[::-1]

print(decToBin(13))