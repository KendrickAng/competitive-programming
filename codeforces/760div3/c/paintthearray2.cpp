#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // try gcd 0, 2, 4...
    ll even = arr[0];
    for (int i = 2; i < n; i+=2) even = __gcd(even, arr[i]);
    bool isAns = true;
    for (int i = 1; i < n; i+=2) {
        if (arr[i] % even == 0) {
            isAns = false;
        }
    }

    if (isAns) {
        cout << even << endl;
        return;
    }

    // try gcd 1, 3, 5...
    ll odd = arr[1];
    for (int i = 3; i < n; i+=2) odd = __gcd(odd, arr[i]);
    isAns = true;
    for (int i = 0; i < n; i+=2) {
        if (arr[i] % odd == 0) {
            isAns = false;
        }
    }

    if (isAns) {
        cout << odd << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}