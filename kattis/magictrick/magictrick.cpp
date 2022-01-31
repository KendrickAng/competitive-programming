#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    unordered_set<char> nodups(s.begin(), s.end());
    if (s.size() == nodups.size()) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}