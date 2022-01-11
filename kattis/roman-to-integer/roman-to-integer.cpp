class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> val = {
            {"I", 1}, 
            {"V", 5}, 
            {"X", 10}, 
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
        };
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            string code;
            if (i == s.size()-1) {
                code = s.substr(i, 1);
                ans += val[code];
            }
            else {
                code = s.substr(i, 2);
                if (val.find(code) != val.end()) {
                    ans += val[code];
                    i++;
                }
                else {
                    code = s.substr(i, 1);
                    ans += val[code];
                }
            }
        }
        return ans;
    }
};