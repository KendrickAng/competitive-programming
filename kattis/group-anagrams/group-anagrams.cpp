#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<size_t, vector<string>> groups;
        for (string &s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            size_t hsh = hash<string>{}(tmp);
            groups[hsh].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &a: groups) {
            ans.push_back(a.second);
        }
        return ans;
    }
};