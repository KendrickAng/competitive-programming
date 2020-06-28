def test(n: int) -> int:
    for i in range(100000):
        n = getNext(n)
        print(n)
        if n == 1:
            return True
    return False

def isHappy(n: int) -> bool:
    dangerous = {4, 16, 37, 58, 89, 145, 42, 20}
    for i in range(20):
        n = getNext(n)
        if n in dangerous:
            return False
    return True

# returns the square of all digits of the number.
def getNext(n: int) -> int:
    if n < 10:
        return n * n

    ret = 0
    while n >= 10:
        nextNum = n % 10
        ret += nextNum * nextNum
        n //= 10

    return ret + n * n

print(isHappy(1)) # true
print(isHappy(7)) # true
print(isHappy(89)) # false
print(isHappy(71)) # false
