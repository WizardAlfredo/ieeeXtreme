numOfIterations = int(raw_input())

for n in range(numOfIterations):
    first = 1
    second = 1
    numStairs = int(raw_input())
    for i in range(numStairs - 1):
        current = first + second
        first = second
        second = current
    print second % 10
