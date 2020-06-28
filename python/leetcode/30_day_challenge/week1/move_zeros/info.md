https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

# Solution
## O(N) time, O(1) space
Use two pointers, one slow and the other iterating the list from left to right.

Invariant 1: The slow pointer keeps all nonzero elements to its left.\
Invariant 2: The space between the slow and fast pointer keeps all zero elements.