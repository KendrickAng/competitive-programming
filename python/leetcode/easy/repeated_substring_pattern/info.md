https://leetcode.com/problems/repeated-substring-pattern/

# Solution
## O(N) time, O(N) space
1. Observe that the repeated substring can form no more than half the length of the string
2. Now form another string (s + s), and remove the first and last letters. Call this s2.
3. Claim: If the string s can be found in s2, then it is formed with a repeated substring pattern.
4. This is because there must be at least 2 substrings in s. By doing (2), we destroy the first and last substring patterns, but leave the middle two (or more) substrings intact.

* However, we don't know what the repeated pattern is, only that it exists.