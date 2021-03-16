# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()
PI = 3.14159265

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)
        
def computeangle(a,b,rad):
    #letter-'A' = pos of the letter
    #compute side length as c = radius*sin(C)/sin(A)
    #where C = angles(a) + angles(b)
    #and A = (180-C)/2
    pos1 = ord(a) - ord('A')
    pos2 = ord(b) - ord('A')
    if pos1>25 or pos2>25 or pos1<0 or pos2<0:
        leng=0
        return leng
    else:
        C_angle = angles[pos1]-angles[pos2] if (angles[pos1]>=angles[pos2]) else angles[pos2]-angles[pos1]
        A_angle = (180-C_angle)/2
        x1 = cos((angles[pos1]*PI)/180)*rad
        x2 = cos((angles[pos2]*PI)/180)*rad
        y1 = sin((angles[pos1]*PI)/180)*rad
        y2 = sin((angles[pos2]*PI)/180)*rad
        leng = sqrt((x1-x2)**2 + (y1-y2)**2)
        return leng

# numpy and scipy are available for use
import numpy
import scipy
from math import sin,sqrt,cos,ceil

length = 26
radius = get_number()
letters = []
angles = []
for i in range(length):
    letters.append(get_word())
    angles.append(get_number())
message = ''
while 1:
    try:
        message = message + get_word()
        fin = '/n'
        if fin in message:
            break
    except EOFError as e:
        break
Uppercase = message.upper() 
tot_dis = 0
for i in range(len(Uppercase)-1):
    dis = computeangle(Uppercase[i],Uppercase[i+1],radius)
    tot_dis = tot_dis + dis
tot_dis = ceil(tot_dis + radius)
print(tot_dis)