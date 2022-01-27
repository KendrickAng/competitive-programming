#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<ll> cumSum;
    cumSum.push_back(0);
    for (int i = 0; i < n; i++) {
        ll last = cumSum.back();
        cumSum.push_back(last + arr[i]);
    }

    // for (auto a: cumSum) cout << a << ' '; cout << endl;

    bool first = true;
    for (int i = 0; i < q; i++) {
        ll x; cin >> x;
        ll ans = 0;
        for (int end = 1; end < cumSum.size(); end++) {
            for (int start = 0; start < end; start++) {
                if (cumSum[end] - cumSum[start] >= x) ans++;
            }
        }
        if (first) first = false;
        else cout << ' ';
        cout << ans;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}

