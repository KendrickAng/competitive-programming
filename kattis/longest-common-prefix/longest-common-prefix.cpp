class Solution {
public:
    string commonPrefix(const string& a, const string& b) {
        if (a.size() == 0 || b.size() == 0) {
            return "";
        }
        string ret = "";
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) ret += a[i];
            else break;
        }
        return ret;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            ret = commonPrefix(ret, strs[i]);
        }
        return ret;
    }
};