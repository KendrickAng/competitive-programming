using namespace std;

class Solution {
public:
    string pad(int &i) {
        if (i >= 10) {
            return to_string(i);
        }
        return "0" + to_string(i);
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        vector<string> keys;
        for (string &s: strings) {
            string key = "0";
            int base = -1;
            for (char c: s) {
                if (base == -1) {
                    base = c;
                } else {
                    int tmp = ((c - base) + 26) % 26;
                    key += pad(tmp);
                }
            }
            groups[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &p: groups) {
            ans.push_back(p.second);
        }
        return ans;
    }
};