# import sys

# def gcd(a, b):
#     return a if b == 0 else gcd(b, a % b)

# def lcm(a, b):
#     return a // gcd(a, b) * b

# for line in sys.stdin:
#     nums = list(map(int, line.split()))
#     ans = nums[0]
#     for num in nums[1:]:
#         ans = lcm(ans, num)
#     print(int(ans))

import sys

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def lcm2(a, b):
    return a / gcd(a, b) * b

for line in sys.stdin:
    nums = list(map(int, line.split()))
    ans1 = nums[0]
    ans2 = nums[0]
    for num in nums[1:]:
        ans1 = lcm(ans1, num)
        ans2 = lcm2(ans2, num)
        if (int(ans1) != int(ans2)):
            print("oh no!", int(ans1), int(ans2))
    print("no difference")