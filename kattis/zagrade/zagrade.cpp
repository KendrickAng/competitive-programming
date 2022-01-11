#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

// this is actually not needed, since the formula is surely valid. just need to emulate the traversal
// and then store the indexes as we find pairs of brackets.
bool isValidPair(string &s, int i, int j) {
    stack<char> stk;
    for (int a = i+1; a < j && a < s.size(); a++) {
        if (s[a] == '(') {
            stk.push('(');
        }
        else if (s[a] == ')') {
            if (stk.empty()) {
                return false;
            }
            else if (stk.top() == '(') {
                stk.pop();
            }
            else {
                return false;
            }
        }
    }
    return stk.empty();
}

string makeString(string s, vector<pair<int,int>> &selected) {
    for (auto &[a,b]: selected) {
        s[a] = ' ';
        s[b] = ' ';
    }
    string ret = "";
    for (char &c: s) {
        if (c != ' ') {
            ret.push_back(c);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    
    // restrict search space to brackets only
    vector<int> ops;
    vector<int> eds;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') ops.push_back(i);
        if (s[i] == ')') eds.push_back(i);
    }

    vector<pair<int,int>> pairs; // bracket pairs
    for (int i: ops) {
        for (int j: eds) {
            if (i < j && isValidPair(s,i,j)) {
                pairs.push_back({i,j});
            }
        }
    }

    int n = pairs.size();
    vector<string> ans;
    unordered_set<string> seen;
    for (int i = 1; i < (1<<n); i++) {
        vector<pair<int,int>> selected;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                selected.push_back(pairs[j]);
            }
        }
        string newStr = makeString(s, selected);
        if (seen.find(newStr) == seen.end()) {
            ans.push_back(newStr);
        }
        seen.insert(newStr);
    }

    sort(ans.begin(), ans.end());
    for (string &s: ans) {
        cout << s << endl;
    }
}