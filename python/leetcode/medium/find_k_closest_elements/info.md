https://leetcode.com/problems/find-k-closest-elements/

# Solution
## O(nlogn) time, O(k) space
Use a custom comparator, imposing an ordering based on how close elements are to x. Since the in-built sorting method should be
stable, we definitely get the smaller element if there is a tie.