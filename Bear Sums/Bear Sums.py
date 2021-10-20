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

def compute(L,hash,E,S):
    for i in range(len(L)):
        complement = S - L[i]
        if complement in hash:
            if complement > L[i]:
                return [L[i],complement]
            else:
                return [complement, L[i]]
        hash[L[i]] = L[i]

iterations = get_number()
for i in range(0,iterations):
    S = get_number()
    E = get_number()
    my_list = []
    for i in range(0,E):
        my_list.append(get_number())
    hash_list = {}
    num = compute(my_list,hash_list,E,S)
    if num is not None:
        if(num[1] > num[0]):
            print(str(num[0]) + " " + str(num[1]))
        else:
            print(str(num[1]) + " " + str(num[0]))
    else:
        print("!OK")
