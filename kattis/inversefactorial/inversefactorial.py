import math
import time

# start = time.perf_counter()

precomputed = {
	"1": 1,
	"2": 2,
	"6": 3,
	"24": 4,
	"120": 5,
	"720": 6,
	"5040": 7,
	"40320": 8,
	"362880": 9,
	"3628800": 10,
}

num = input()

if num in precomputed:
    print(precomputed[num])
else:
    n = len(str(num))
    sofar = 0
    for i in range(1, 1000001):
        sofar += math.log10(i)
        if math.floor(sofar) + 1 == n:
            print(i)
            break

# end = time.perf_counter()
# print(end - start)