import time

def decToBin(decNumber):
    result = ""
    while decNumber > 0:
        result += chr(decNumber % 2 + ord('0'))
        decNumber = decNumber // 2

    return result[::-1]


def measure(numOfCases):
    start = time.time()

    for i in range(0, numOfCases):
        decToBin(i)

    end = time.time()
    return end - start


measureSum = 0
numOfCases = 5000
count = 1
while numOfCases < 1000000:
    for i in range(0, 100):
        measureSum += measure(numOfCases) * 1000000

    print(f'Average exec time for { numOfCases }: { measureSum / 100 }µs')
    numOfCases += 5000 * count
    measureSum = 0
    count += 1
