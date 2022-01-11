#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// ll gcd(ll a, ll b) {
//     return b == 0 ? a : gcd(b, a%b);
// }

// ll lcm(ll a, ll b) {
//     return a / gcd(a, b) * b;
// }

void solve() {
    int w; cin >> w;

    ll ans = -1;
    bool exceeded = false;
    for (int i = 0; i < w; i++) {
        ll temp; cin >> temp;
        if (ans == -1) {
            ans = temp;
        } else {
            ans = lcm(ans, temp);
        }
        // cout << "ans is " << ans << endl;

        if (ans > 1e9) {
            exceeded = true;
        }
    }

    if (exceeded) {
        cout << "More than a billion." << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}