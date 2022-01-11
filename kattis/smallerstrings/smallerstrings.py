def is_palindrome(s):
    for i in range(len(s)//2):
        if s[i] != s[-(i+1)]:
            return False
    return True

t = int(input())
for case in range(t):
    n, k = list(map(int, input().split()))
    s = input()

    # generate allowed alphabets
    allowed_letters = set()
    for offset in range(k):
        allowed_letters.add(chr(ord('a')+offset))

    ans = 1
    for i in range(len(s)//2):
        tmp = min(ord(s[i]), ord(s[-(i+1)])) - ord('a') + 1
        ans *= min(tmp, k)

    if (len(s) % 2 != 0):
        print("hell")
        print( min(ord(s[len(s)//2])-ord('a')+1, k))
        ans *= min(ord(s[len(s)//2])-ord('a')+1, k)

    if is_palindrome(s):
        print(f"{s} is palindrome")
        ans -= 1
    
    print(f"Case #{case+1}: {ans}")
