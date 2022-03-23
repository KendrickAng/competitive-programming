from math import floor, gamma, lgamma, exp, isclose

# https://www.wolframalpha.com/input?i=%28x+choose+1%29+times+%28n+choose+%28p-1%29%29+divided+by+%28%28n%2Bx%29+choose+%28p%29%29
def f(n, p, x):
    return p*x*gamma(n+1)*gamma(n-p+x+1)/(gamma(n-p+2)*gamma(n+x+1))

def f2(n, p, x):
    return x*p*exp(lgamma(n-p+x)-lgamma(n-p+1)-lgamma(n+x)+lgamma(n))

N, P = map(int, input().split())
X = floor(N/(P-1))
# print(N, P, X, f(N, P, X))
# for i in range(1, 10000):
#     if not isclose(f(N, P, i), f2(N+1, P, i)):
#         print(N, P, i, f(N, P, i), f2(N+1, P, i))
print(f2(N+1, P, X))