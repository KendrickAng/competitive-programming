https://leetcode.com/problems/number-of-good-ways-to-split-a-string/submissions/

# Solution
## O(N) time, O(N) space
Note: `N` refers to the length of the input string.

Keep a set `left` containing the elements on the left side of a pointer, and a `right` set for elements to the right of a pointer.
Iterate from left to right, updating the elements in both `left` and `right`.
Whenever the unique elements in both sets are the same, add one to the return value.