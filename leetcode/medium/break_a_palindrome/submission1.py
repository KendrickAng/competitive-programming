def breakPalindrome(palindrome):
    palindrome = list(palindrome) # allow mutation

    if len(palindrome) == 1:
        return ""

    # for odd string length, ignore the middle letter
    mid = len(palindrome) // 2
    for i in range(len(palindrome)):
        if len(palindrome) % 2 != 0 and i == mid:
            continue
        if palindrome[i] != 'a':
            palindrome[i] = 'a'
            return ''.join(palindrome)

    # no candidate, all legitimate characters are 'a'
    palindrome[-1] = 'b'
    return ''.join(palindrome)

print(breakPalindrome("aa"))
print(breakPalindrome("abccba"))
print(breakPalindrome("a"))