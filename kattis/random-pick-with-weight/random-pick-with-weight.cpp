#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    default_random_engine e;
    discrete_distribution<int> dd;
    
    Solution(vector<int>& w) {
        dd = discrete_distribution(w.begin(), w.end());
    }
    
    int pickIndex() {
        return dd(e);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */