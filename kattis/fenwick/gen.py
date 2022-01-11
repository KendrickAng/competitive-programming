with open("big.in", "w") as f:
    n = 5_000_000
    q = 5_000_000
    f.write(f"{n} {q}\n")
    for _ in range(q//2):
        f.write(f"+ 0 1000000000\n")
        f.write(f"? {n}\n")
