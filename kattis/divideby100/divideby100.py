from decimal import getcontext, Decimal, MAX_PREC

a = input()
b = input()

getcontext().prec = 1000000
a2 = Decimal(a)
b2 = Decimal(b)
c = a2 / b2
print(f"{c:f}")