def makeAnagram(a, b):
    aArr = [0] * 26
    bArr= [0] * 26
    for letter in a:
        aArr[ord(letter) - ord('a')] += 1
    for letter in b:
        bArr[ord(letter) - ord('a')] += 1
    deletions = 0
    for i in range(len(aArr)):
        deletions += max(aArr[i], bArr[i]) - min(aArr[i], bArr[i])
    return deletions

print(makeAnagram("cde", "abc"))