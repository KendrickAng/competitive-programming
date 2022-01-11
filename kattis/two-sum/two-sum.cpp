#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums.size(); i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());

        int front = 0;
        int back = arr.size()-1;
        while (true) {
            int sum = arr[front].first + arr[back].first;
            if (sum == target) return {arr[front].second, arr[back].second};
            else if (sum < target) front++;
            else if (sum > target) back--;
        }
    }
};