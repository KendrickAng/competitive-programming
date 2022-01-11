class Solution:
    
    def isPalindrome(self, s: str) -> bool:
        # normalize the string
        normStr = "".join([c.lower() for c in s if c.isalnum()])
        print(normStr)
        
        # determine if palindrome
        
        return normStr[::-1] == normStr