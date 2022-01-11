#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s = "";
    for (int i = 0; i < n-2; i++) {
        string tmp; cin >> tmp;
        if (s == "") {
            s += tmp;
        } else if (s.back() == tmp[0]) {
            s += tmp[1];
        } else {
            s += tmp;
        }
    }

    while (s.size() < n) {
        s += "a";
    }

    cout << s << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}