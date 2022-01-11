class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    int goal;
    
    void dfs(vector<int> &sofar, int curr, int idx) {
        if (idx >= arr.size()) return;
        if (curr > goal) return;
        if (curr == goal) {
            vector<int> toAdd(sofar);
            ans.push_back(toAdd);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            int e = arr[i];
            sofar.push_back(e);
            dfs(sofar, curr+e, i);
            sofar.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        goal = target;
        vector<int> soFar;
        dfs(soFar, 0, 0);
        return ans;
    }
};