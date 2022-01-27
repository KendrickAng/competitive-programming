import fractions

def frac(x1, n1):
    if n1 == 0: return fractions.Fraction(f"0.{x1}")
    n = len(x1)
    tendiv = n - n1
    repeating = x1[n-n1:] if x1[n-n1:] else "0"
    nonrepeating = x1[:n-n1] if x1[:n-n1] else "0"
    # print(f"{tendiv} {nonrepeating} {repeating}")
    return raToFrac(nonrepeating) + irraToFrac(repeating) * fractions.Fraction(1, 10**tendiv)

def raToFrac(nonrepeating):
    return fractions.Fraction(int(nonrepeating), 10**(len(nonrepeating)))

def irraToFrac(repeating):
    return fractions.Fraction(int(repeating), (10**len(repeating)) - 1)

t = int(input())
for _ in range(t):
    x1, n1, x2, n2 = input().split()
    a = frac(x1, int(n1))
    b = frac(x2, int(n2))
    c = a + b
    print(f"{c.numerator}/{c.denominator}")
