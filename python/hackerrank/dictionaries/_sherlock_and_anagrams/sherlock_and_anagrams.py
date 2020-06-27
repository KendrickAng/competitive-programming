def sherlockAndAnagrams(str):
    if len(str) <= 1:
        return 0

    num_pairs = 0
    for n in range(1, len(str)):
        # generate set of anagrams of length n
        s = set()
        for i in range(len(str) - n + 1):
            s.add(frozenset(str[i:i+n]))
        print(s)
        # check anagrams of length n
        total = 0
        for i in range(len(str) - n + 1):
            substring = str[i:i+n]
            if frozenset(substring) in s:
                total += 1
        num_pairs += (total / 2) - 1
    return num_pairs

print(sherlockAndAnagrams("abba"))
print(sherlockAndAnagrams("kkkk"))