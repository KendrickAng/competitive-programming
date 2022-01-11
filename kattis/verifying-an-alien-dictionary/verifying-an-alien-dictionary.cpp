#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> wordsSort(words);
        unordered_map<char, int> mapping;
        for (int i = 0; i < order.size(); i++) {
            mapping[order[i]] = i;
        }
        
        sort(wordsSort.begin(), wordsSort.end(), [&](const string& a, const string& b) {
            int n = min(a.size(), b.size());
            for (int i = 0; i < n; i++) {
                char aa = a[i];
                char bb = b[i];
                if (mapping[aa] != mapping[bb]) {
                    if (mapping[aa] < mapping[bb]) return true;
                    else return false;
                }
            }
            return a.size() < b.size();
        });
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != wordsSort[i]) return false;
        }
        return true;
    }
};