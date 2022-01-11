from collections import Counter

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        ctr = Counter(guess)
        cows = 0
        bulls = 0
        
        # count bulls first
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                ctr[secret[i]] -= 1
        
        for i in range(len(secret)):
            sEle = secret[i]
            gEle = guess[i]
            if sEle != gEle:
                if ctr[sEle] > 0:
                    cows += 1
                    ctr[sEle] -= 1
        
        return f"{bulls}A{cows}B"
    
"""
bulls = # digits in guess in correct pos
cows = # digits in guess in the secret number but in wrong pos
1807
7810

bulls = 1
cows = 3

1123
0111
bulls = 1
cows = 1

# count bulls
chars that match in secret and guess

# ount cows
chars with a mismatch but that numbner exists down the line

generate counter for guess
iterate both secte and guess
    if both eles match:
        bulls += 1
        minus secret's char from counter
    else:
        if secret's char in in counter
            cows += 1
            minus secret's char from counter
"""