import fractions

t = int(input())
for _ in range(t):
    a, an, b, bn = input().split()
    an = int(an)
    bn = int(bn)

    arep = a[len(a)-an:]
    if not arep: arep = "0"
    brep = b[len(b)-bn:]
    if not brep: brep = "0"

    f1 = fractions.Fraction("0." + a + (arep * 12700)).limit_denominator()
    f2 = fractions.Fraction("0." + b + (brep * 12700)).limit_denominator()
    f3 = f1 + f2
    print(f"{f3.numerator}/{f3.denominator}")