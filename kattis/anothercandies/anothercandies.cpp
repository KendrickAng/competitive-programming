#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll rem = 0;
    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        rem += (tmp % n);
    }

    if (rem % n == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}