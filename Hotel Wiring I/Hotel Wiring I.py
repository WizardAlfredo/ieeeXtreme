def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


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
iter = get_number()
for _ in range(iter):

    floors = get_number()
    rooms = get_number()
    switches_to_off = get_number()
    lights_on = []
    for _ in range(floors):
        lights_on.append(get_number())
    lights_on.sort()
    for i in range(switches_to_off):
        lights_on[i] = rooms - lights_on[i]
    print(sum(lights_on))
