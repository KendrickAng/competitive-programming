class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long sum = 0;
        long ans = -1e6;
        for (int num: nums) {
            sum += num;
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        return ans;
    }
};