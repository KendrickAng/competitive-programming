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
    return mod(x, m);
}

void solve(ll n, ll t) {
    for (int i = 0; i < t; i++) {
        ll x, y;
        string op;
        cin >> x >> op >> y;

        ll ans;
        if (op == "+") {
            ans = ((x % n) + (y % n)) % n;
        } else if (op == "-") {
            ans = ((x % n) - (y % n)) % n;
        } else if (op == "*") {
            ans = ((x % n) * (y % n)) % n;
        } else { // divide
            ll invMod = modInverse(y, n);
            if (y == 0 || invMod == -1) {
                ans = -1;
            } else {
                ans = ((x % n) * invMod) % n;
            }
        }

        if (ans == -1) cout << ans << endl;
        else {
            while (ans < 0) ans += n;
            cout << ans << endl;
        }
    }
}

int main() {
    ll n, t; cin >> n >> t;
    while (n != 0 and t != 0) {
        solve(n, t);
        cin >> n >> t;
    }
}