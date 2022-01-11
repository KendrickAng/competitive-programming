class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ss(128, 0);
        vector<int> tt(128, 0);
        for (char c: s) ss[c]++;
        for (char c: t) tt[c]++;
        return ss == tt;
    }
};