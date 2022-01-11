class Solution:
    def decodeString(self, s: str) -> str:
        ans = []
        i = 0

        # eats a k[encoded_string]
        def helper():
            nonlocal i
            ret = ""

            # eat the number
            num = ""
            while s[i].isdigit():
                num += str(s[i])
                i += 1

            # at a square bracket, skip it
            i += 1
            toRepeat = ""
            while s[i] != "]":
                if s[i].isdigit():
                    toRepeat += helper()
                else:
                    toRepeat += s[i]
                i += 1

            return int(num) * toRepeat

        while i < len(s):
            c = s[i]
            if c.isalpha():
                ans.append(c)
            else:
                ans.append(helper())
            i += 1

        return "".join(ans)    
"""
ans = []
i = 0

# eats a k[encoded_string]
def helper(i):
    nonlocal i
    ret = ""
    
    # eat the number
    num = ""
    while s[i].isdigit():
        num += str(s[i])
        i += 1
    
    # at a square bracket, skip it
    i += 1
    toRepeat = ""
    while s[i] != "]":
        if s[i].isdigit():
            toRepeat += helper(i)
        else:
            toRepeat += s[i]
        i += 1
    
    return int(num) * toRepeat

while i < len(s):
    c = s[i]
    if c.isalpha():
        ans.append(c)
    else:
        ans.append(helper(i))
    i += 1

return "".join(ans)
"""