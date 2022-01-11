BIG = 1000000007

def is_palindrome(s):
    for i in range(len(s)//2):
        if s[i] != s[-(i+1)]:
            return False
    return True

def get_tmp(c, k):
    tmp = ord(c)-ord('a')+1
    if k < tmp:
        return k
    elif k > tmp:
        return tmp-1
    else:
        return k - 1

def count2(s, k, idx, isLimiterOff, sofar):
    if len(s) % 2 != 0 and idx > len(s) // 2:
        return sofar
    if len(s) % 2 == 0 and idx >= len(s) // 2:
        return sofar

    if isLimiterOff:
        return count2(s, k, idx+1, True, sofar * (k % BIG))
    else:
        # tmp = min(k-1, min(ord(s[idx]), ord(s[-(idx+1)])) - ord('a'))
        tmp = get_tmp(s[idx], k) 
        return count2(s, k, idx+1, False, sofar * (1 % BIG))\
         + count2(s, k, idx+1, True, sofar* (tmp % BIG))

def count(s, k):
    limitOn = count2(s, k, 1, False, 1 % BIG)
    tmp = get_tmp(s[0], k)
    print(tmp)
    limitOff = count2(s, k, 1, True, tmp % BIG)
    ans = limitOn + limitOff
    if is_palindrome(s):
        ans -= 1
    return ans

t = int(input())
for case in range(t):
    n, k = list(map(int, input().split()))
    s = input()
    
    print(f"Case #{case+1}: {count(s, k)}")

