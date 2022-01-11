#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = -1;
        while (l != r) {
            int h1 = height[l];
            int h2 = height[r];
            int area = min(h1, h2) * (r-l);
            ans = max(ans, area);
            if (h1 < h2) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};