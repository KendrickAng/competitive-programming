#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> chars(128, 0);
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < n) {
            char c = s[right];
            chars[c]++;

            while (chars[c] > 1) {
                char cc = s[left];
                chars[cc] -= 1;
                left++;
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};