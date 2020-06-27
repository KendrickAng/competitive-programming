def substrCount(n, s):
    # 1st pass - generate tuples (chr, # continous chrs)
    tuples = []
    curr = None
    num_same_letters = 0

    for c in s:
        if c == curr:
            num_same_letters += 1
        else:
            if curr is not None:
                tuples.append((curr, num_same_letters))
            curr = c
            num_same_letters = 1
    tuples.append((curr, num_same_letters))

    ans = 0
    # 2nd pass - first case
    for letter, count in tuples:
        ans += ((count * (count + 1)) // 2)

    # 3rd pass - second case
    for i in range(1, len(tuples)-1):
        chr1, n1 = tuples[i - 1]
        chr2, n2 = tuples[i]
        chr3, n3 = tuples[i + 1]
        if chr1 == chr3 and n2 == 1:
            ans += min(n1, n3)
    return ans

print(substrCount(7, "abcbaba"))
print(substrCount(5, "asasd"))