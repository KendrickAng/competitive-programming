from decimal import Decimal

a, b, c = list(map(int, input().split()))

if b % c == 0:
    print(a * b // c)
else:
    e = format(Decimal(a) * Decimal(b) / Decimal(c), '.18f')
    print(e)
