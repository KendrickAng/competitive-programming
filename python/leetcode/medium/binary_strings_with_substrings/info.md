https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

# Solution
# O(Snlogn) time
Just convert the base-10 integer to base-2 (length log(n)), then check if it's in the string (O(S))

I have no idea why it passes at 92%...