https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/

# Solution
## O(N) time, O(1) space
### Kadane's algorithm

Idea: If we know the maximum subarray up to element j, then we know the maximum subarray up to
element j+1 through this formula which can be proved through mathematical induction.

```Best_i+1 = max(Best_i + Element_j, Element_j)```

Best_i+1 = max subarray sum with element J added\
Best_i   = max subarray sum without element J

https://thirumal.blog/2018/03/18/kadane-deep-dive/ - provides a good proof on why this works.