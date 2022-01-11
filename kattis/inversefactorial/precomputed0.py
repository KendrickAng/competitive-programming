import math
import time

# start = time.perf_counter()

# with open("4.in", "w") as file:
#     file.write(str(math.factorial(25000)))

sofar = 1
with open("precomputed2.py", "w") as file:
    lines = []
    lines.append("precomputed = {\n")
    for i in range(1, 26000):
        if i % 1000 == 0:
            print(f"done {i}")
        sofar *= i
        h = hash(sofar)
        lines.append(f"\t{h}: {i},\n")
    lines.append("}\n")
    file.writelines(lines)

# end = time.perf_counter()
# print(end - start)