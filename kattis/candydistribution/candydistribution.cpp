#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod(ll a, ll m) {
    return ((a % m) + m) % m;
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

ll modInverse(ll b, ll m) {
    ll x, y;
    ll d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    // b * x + m * y == 1, now apply (mod m) to get b * x == 1
    return mod(x, m);
}

void solve() {
    ll k, c; cin >> k >> c;

    if (k == 1 && c == 1) {
        cout << 2 << endl;
    } else if (k == 1) { // one child
        cout << 1 << endl;
    } else if (c == 1) { // each bag has one sweet
        cout << k + 1 << endl;
    } else {
        // find c^-1 mod k
        ll ans = modInverse(c, k);
        if (ans == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}