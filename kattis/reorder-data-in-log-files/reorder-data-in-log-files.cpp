#include <bits/stdc++.h>

class Solution {
private:
    bool isDigitlog(const string &s) {
        return isdigit(s[s.size()-1]);
    }
    bool isLetterlog(const string &s) {
        return !isDigitlog(s);
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string& a, const string& b) {
            if (isLetterlog(a) && isLetterlog(b)) {
                istringstream ssa(a);
                istringstream ssb(b);
                string ia, ib, ta, tb;
                vector<string> ca, cb;
                ssa >> ia;
                ssb >> ib;
                while (ssa >> ta) ca.push_back(ta);
                while (ssb >> tb) cb.push_back(tb);
                if (ca == cb) return ia < ib;
                return ca < cb;
            }
            else {
                return isLetterlog(a);
            }
        });
        return logs;
    }
};