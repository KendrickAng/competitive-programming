class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumUpTo;
        // sumUpTo[0] = 1;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sumUpTo[sum]++;
            sum += nums[i];
            // find if the diff exists
            int diff = sum - k;
            if (sumUpTo.find(diff) != sumUpTo.end()) {
                ans += sumUpTo[diff];
            }
        }
        
        return ans;
    }
};