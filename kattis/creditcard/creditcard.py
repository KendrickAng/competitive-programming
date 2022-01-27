from decimal import Decimal, getcontext, ROUND_HALF_UP

getcontext().prec = 5000

def solve():
    mthRate, bal, amt = map(Decimal, input().split())
    mthRate /= 100

    for i in range(1200):
        interest = (mthRate * bal).quantize(Decimal('.01'), rounding=ROUND_HALF_UP)
        bal += interest
        bal -= amt
        # print(bal)
        if bal <= 0:
            print(i+1)
            return

    print("impossible")

n = int(input())
for _ in range(n):
    solve()
    
