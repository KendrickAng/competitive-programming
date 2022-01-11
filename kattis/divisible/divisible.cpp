#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll d, n; cin >> d >> n;

    ll ans = 0;
    ll cumSum = 0;
    unordered_map<int, int> hoho;
    hoho[0] = 1;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cumSum += tmp;
        int key = cumSum % d;
        if (hoho.find(key) != hoho.end()) {
            ans += hoho[key];
        }
        hoho[key]++;
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}