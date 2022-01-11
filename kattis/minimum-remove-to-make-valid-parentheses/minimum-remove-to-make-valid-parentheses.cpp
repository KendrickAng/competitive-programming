#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBracket(char c) {
        return c == '(' || c == ')';
    }
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>> stk;
        string s2 = "";
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (!isBracket(c)) {
                s2.push_back('Y');
                continue;
            }
            if (c == '(') {
                stk.push({c, i});
                s2.push_back('N');
            }
            else if (c == ')') {
                if (stk.empty()) {
                    s2.push_back('N'); // ignore
                }
                else if (stk.top().first == '(') {
                    auto p = stk.top(); 
                    stk.pop();
                    s2[p.second] = 'Y';
                    s2.push_back('Y');
                }
                else {
                    throw "wrong";
                }
            }
        }
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (s2[i] == 'Y') ret.push_back(s[i]);
        }
        return ret;
    }
};