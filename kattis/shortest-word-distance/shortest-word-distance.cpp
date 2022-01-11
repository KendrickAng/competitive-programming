#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) v1.push_back(i);
            if (wordsDict[i] == word2) v2.push_back(i);
        }
        int ans = 1e9;
        for (auto a: v1) {
            for (auto b: v2) {
                ans = min(ans, abs(a-b));
            }
        }
        return ans;
    }
};