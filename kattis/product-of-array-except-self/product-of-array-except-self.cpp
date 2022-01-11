class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size());
        int pref = 1;
        for (int i: nums) {
            prefix.push_back(pref);
            pref *= i;
        }
        int suf = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = suf;
            suf *= nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(suffix[i] * prefix[i]);
        }
        return ans;
    }
};