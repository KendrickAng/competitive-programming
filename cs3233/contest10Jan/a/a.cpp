#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, v; cin >> n >> v;
    if (v <= n) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= (i % v);
            ans %= v;
        }
        cout << ans << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}