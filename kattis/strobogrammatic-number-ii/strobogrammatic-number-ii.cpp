class Solution {
public:
    vector<pair<string,string>> strobes = {
        {"0", "0"}, {"1", "1"}, {"6","9"}, {"8", "8"}, {"9", "6"}
    };
    
    vector<string> helper(int n) {
        if (n == 1) return { "0", "1", "8" };
        if (n == 2) return { "00", "11", "69", "88", "96" };
        
        vector<string> prev = helper(n - 2);
        vector<string> ans;
        for (string &s: prev) {
            for (auto p: strobes) {
                ans.push_back(p.first + s + p.second);
            }
        }
        return ans;
    }
    
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) return { "0", "1", "8" };
        if (n == 2) return { "11", "69", "88", "96" };
        
        vector<string> ret = helper(n);
        
        // remove the ones with leading/trailing zeros
        vector<string> ans;
        for (auto &s: ret) {
            if (s[0] == '0' and s[s.size()-1] == '0') continue;
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};