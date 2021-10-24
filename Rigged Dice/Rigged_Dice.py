# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy
import scipy

T = get_number() # number of tests

for i in range(T):
    N = get_number() #number of rounds
    Alice = list()
    Bob = list()
    for i in range(N):
        Alice.append(get_number())
        Bob.append(get_number())
    AS = Alice[0]
    BS = Bob[0]
    D1 = Alice[0]
    D2 = Bob[0]
    x1 = 0
    x2 = ~x1
    #print(AS,BS,D1,D2)
    #print(x1,x2)
    for i in range(1,len(Alice)):
        if AS != BS:
            x1 = ~x1
            x2 = ~x2
        if x1 == 0:
            D1 = D1 + Alice[i]
            D2 = D2 + Bob[i]
        if x1 == -1:
            D1 = D1 + Bob[i]
            D2 = D2 + Alice[i]
        AS = AS + Alice[i]
        BS = BS + Bob[i] 
        #print(i,x1,x2,AS,BS,D1,D2)
    if D1 > D2:
        print("1")
    else:
        print("2")
