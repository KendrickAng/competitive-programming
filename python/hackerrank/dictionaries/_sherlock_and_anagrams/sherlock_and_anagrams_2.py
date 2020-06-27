def sherlockAndAnagrams(str):
    def generate_signature(substring):
        sig = [0] * 26  # 26 letters of alphabet
        for letter in substring:
            sig[ord(letter) - 97] += 1
        return tuple(sig)
    def n_choose_2(n):
        return (n * (n - 1)) // 2
    """
    Loop through all possible substrings and generate their signatures, adding as key to dict. O(|s|^2), arithmetic sum.
    Loop through each signature, where there are nC2 anagrams for n strings with same signature.
    """
    # create all possible substrings of all lengths
    d = {}
    for n in range(1, len(str)):
        for i in range(len(str)-n+1):
            substring = str[i:i+n]
            signature = generate_signature(substring)
            if signature not in d:
                d[signature] = 1
            else :
                d[signature] += 1
    # loop through each sig
    total = 0
    for key, val in d.items():
        total += n_choose_2(val)
    return total

print(sherlockAndAnagrams("abba"))
print(sherlockAndAnagrams("kkkk"))