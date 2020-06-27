def twoStrings(s1, s2):
    s = set()
    for letter in s1:
        # unused value
        s.add(letter)
    for letter in s2:
        if letter in s:
            return "YES"
    return "NO"

print(twoStrings("hello", "world"))
print(twoStrings("hi", "world"))