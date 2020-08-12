https://leetcode.com/problems/pascals-triangle-ii/

# Solution
# O(k) time, O(k) space
Note: (k = row index where idx 0 = first row of Pascal's Triangle)

Suppose i = row index, j = column index, both start from 0. Then the value at ith row, jth column = `(i choose j)`.
Have a simple for loop and calculate all values at that row.