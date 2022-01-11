class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums, int idx, vector<int> sofar) {
        int n = nums.size();
        if (idx > n) return;
        if (idx == n) {
            ans.push_back(sofar);
            return;
        }
        int curr = nums[idx];
        
        vector<int> choose(sofar); choose.push_back(curr);
        helper(nums, idx+1, choose);
        helper(nums, idx+1, sofar);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0, vector<int>{});
        return ans;
    }
};