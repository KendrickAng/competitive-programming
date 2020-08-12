https://leetcode.com/problems/h-index/

# Solution
## O(nlogn) time, O(1) space
Sort the array, then scan from left to right, keeping track of the number of elements to the right of the iterating pointer (plus the current element), `numRight`.
The moment the current element is greater or equal to `numRight`, our condition is satisfied - return `numRight` as answer.