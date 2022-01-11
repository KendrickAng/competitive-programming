#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    s.push_back('a');
    s.push_back('a');
    for (int i = 0; i < n; i++) {
        if (s[i] == ':' and s[i+1] == ')') {
            cout << i << endl;
        } else if (s[i] == ';' and s[i+1] == ')') {
            cout << i << endl;
        } else if (s[i] == ':' and s[i+1] == '-' and s[i+2] == ')') {
            cout << i << endl;
        } else if (s[i] == ';' and s[i+1] == '-' and s[i+2] == ')') {
            cout << i << endl;
        }
    }
}