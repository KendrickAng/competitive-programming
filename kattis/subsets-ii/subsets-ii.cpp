class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<string> seen;
    
    string vecToStr(vector<int> &v) {
        string ret = "";
        for (int i: v) ret.append(to_string(i));
        return ret;
    }
    
    void subsets(vector<int> &nums, int idx, vector<int> sofar) {
        int n = nums.size();
        if (idx == n) {
            string key = vecToStr(sofar);
            if (seen.find(key) == seen.end()) {
                seen.insert(key);
                ans.push_back(sofar);
            }
            return;
        }
        if (idx > n) return;
        
        int curr = nums[idx];
        vector<int> pick(sofar);
        pick.push_back(curr);
        
        subsets(nums, idx+1, pick); // pick
        subsets(nums, idx+1, sofar); // don't pick
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsets(nums, 0, vector<int>{});
        return ans;
    }
};