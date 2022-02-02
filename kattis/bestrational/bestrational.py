import fractions
import math

def solve():
    tokens = input().split()
    K = tokens[0]
    maxDenom = int(tokens[1])
    x = float(tokens[2])

    currAns = None

    maxNum = round(maxDenom * x)
    for numer in range(maxNum, -1, -1):
        denom = round(numer / x)
        # numer = round(x * denom)
        if math.gcd(numer, denom) != 1: continue
        frac = fractions.Fraction(numer, denom)
        if not currAns:
            currAns = frac
        elif abs(x - frac) <= abs(x - currAns):
            currAns = frac

    print(f"{K} {currAns.numerator}/{currAns.denominator}")


t = int(input())
for _ in range(t):
    solve()
