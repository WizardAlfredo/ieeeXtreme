# numpy and scipy are available for use
import numpy
import scipy

T = get_number() # test case

def running_up_stairs(n, m):
    ways = [1] + [None] * n
    for i in range(1, n+1):
        ways[i] = sum(ways[max(0, i-m):i])
    return ways[n]
    
for i in range(T):
    step = get_number()
    ways = runnning_up_stairs(step,2)
    print(ways)
