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

from math import ceil

# Without the worker price
width = get_number()
height = get_number()
tile_width = get_number()
tile_height = get_number()
tile_price = get_number()
worker_price = get_number()

tiles_wid = ceil(width/tile_width)
tiles_heig = ceil(height/tile_height)
cut=0
if ((tiles_wid*tile_width - width)!=0):
    cut += height

if ((tiles_heig*tile_height - height)!=0):
    cut += width  
    
price = (ceil(tiles_wid*tiles_heig/10) * tile_price) + (cut * worker_price)  
print(price) 
