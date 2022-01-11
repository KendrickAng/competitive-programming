#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                hi = mid -1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};