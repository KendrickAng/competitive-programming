#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMerge(vector<int> &a, vector<int> &b) {
        return a[1] >= b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int ptr = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < n-1; i++) {
            vector<int> &a = intervals[i];
            vector<int> &b = intervals[i+1];
            if (canMerge(a, b)) { // merge
                int first = min(a[0], b[0]);
                int second = max(a[1], b[1]);
                b[0] = first;
                b[1] = second;
                if (i == n-2) {
                    ans.push_back(b);
                }
            }
            else {
                ans.push_back(a);
                if (i == n-2) {
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};