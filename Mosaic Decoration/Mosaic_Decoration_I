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
from math import ceil

numofiterations = get_number() #number of iterations
black_price = get_number() #black tiles price
pink_price = get_number() #pink tiles price

black = []
pink = []
for i in range(numofiterations):
    black.append(get_number())
    pink.append(get_number())
tot_black = sum(black)
tot_pink = sum(pink)
money = ceil(tot_black/10)*black_price + ceil(tot_pink/10)*pink_price
print(money)
