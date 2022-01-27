import random

with open("gen.in", "w") as file:
    lines = []
    count = 0
    for day in range(1, 29):
        for month in range(1, 13):
            for year in range(9999, 100000):
                lines.append(f"{day} {month} {year}\n")
                count += 1
                if count >= 10000: break
            if count >= 10000: break
        if count >= 10000: break
    lines.append("0 0 0")
    file.writelines(lines)