#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
    string s;
    
    int dp(int start, int end) { // end inclusive
        if (start == end) return true;
        if (abs(start-end) == 1) return s[start] == s[end];
        int &ans = memo[start][end];
        if (ans != -1) return ans;
        return ans = (s[start] == s[end]) && dp(start+1, end-1);
    }
public:
    string longestPalindrome(string ss) {
        int MAX_N = 1010;
        memo = vector<vector<int>>(MAX_N, vector<int>(MAX_N, -1));
        s = ss;
        
        //dp(0, s.size()-1);
        
        //cout << memo[1][4] << endl;
        
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (dp(i, j) && ((j-i+1) >= (end-start+1))) {
                    start = i;
                    end = j;
                }
            }
        }
        
        return s.substr(start, end-start+1);
    }
};