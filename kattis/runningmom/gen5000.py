
with open("5000.in", "w") as f:
    f.write("5000\n")
    for i in range(4999):
        curr = i
        next = i + 1
        f.write(f"v{curr} v{next}\n")
    f.write(f"v4999 v0\n")
    for i in range(1000):
        f.write(f"v{i}\n")
