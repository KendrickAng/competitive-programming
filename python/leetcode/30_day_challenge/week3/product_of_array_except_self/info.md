https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/

# Solution
## O(N) time, O(N) space
Preprocess the array:
1. create a `prefix` array where `prefix[i]` contains the product of all elements before `i`.
2. Similarly, create a `suffix` array where `suffix[i]` contains the product of all elements after `i`.
3. the answer is `prefix[i] * suffix[i]` for all i.

## O(N) time, O(1) space
Use the answer array, form the prefix array with it, then update the prefix array by calculating suffix on the fly.
No extra arrays are created.