def breakPalindrome(palindrome):
    """
    brute force solution - iterate all characters, for each replace with every letter of
    the alphabet, then check - if not a palindrome, replace with minimum of current string.
    """
    def isPalindrome(string):
        for i in range(len(string) // 2):
            if string[i] != string[len(string) - 1 - i]:
                return False
        return True

    if len(palindrome) == 1:
        return ""

    ans = None
    alphabet = [chr(i) for i in range(ord('a'), ord('z'))]

    string = list(palindrome)
    for i in range(len(string)):
        # ignore middle letter for odd length strings
        if len(string) % 2 != 0 and i == len(string) // 2:
            pass

        for character in alphabet:
            string = list(palindrome)
            string[i] = character
            myString = ''.join(string)
            if not isPalindrome(myString):
                if ans is None:
                    ans = myString
                if myString != palindrome:
                    ans = min(ans, myString)
    return ans


print(breakPalindrome("aa"))
print(breakPalindrome("abccba"))
print(breakPalindrome("a"))