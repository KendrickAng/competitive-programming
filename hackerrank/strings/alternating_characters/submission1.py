def alternatingCharacters(s):
    prevLetter = None
    currLetter = None
    deletions = 0
    i = 0
    while i < len(s):
        currLetter = s[i]

        while i < len(s) and currLetter == prevLetter:
            deletions += 1
            if i+1 < len(s):
                currLetter = s[i+1]
                i += 1
            else:
                break

        prevLetter = s[i]
        i += 1
    return deletions

print(alternatingCharacters("AAAA"))
print(alternatingCharacters("BBBBB"))
print(alternatingCharacters("ABABABAB"))
print(alternatingCharacters("BABABA"))
print(alternatingCharacters("AAABBB"))