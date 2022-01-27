#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define LSOne(S) ((S) & -(S))

class FenwickTree {
private:
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n, 0);
    }
    void update(int i, int delta) {
        for (; i <= size; i += LSOne(i)) tree[i] += delta;
    }
    int rsq(int i) {
        int total = 0;
        for (; i > 0; i -= LSOne(i)) total += tree[i];
        return total;
    }
    int rsq(int i, int j) { // [i, j]
        return rsq(j) - rsq(i-1);
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    FenwickTree ft(n+10);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // create cumulative sum array
    ll sum = 0;
    vector<int> cumSum(n);
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        cumSum[i] = sum;
    }

    // fenwick data compression
    unordered_map<int, int> revMapping; revMapping.reserve(n);
    for (int i = 1; i <= n; i++) {
        int num = cumSum[i-1];
        revMapping[num] = i;
    }

    // answer queries
    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        ll ans = 0;
        for (int j = 0; j < cumSum.size(); j++) {
            int idx = revMapping[cumSum[j]];
            ans += ft.rsq(idx);
            ft.update(idx, 1);
        }
    }

    bool first = true;
    for (int num: arr) {
        if (first) first = false;
        else cout << ' ';
        int idx = revMapping[num];
        cout << ft.rsq(idx);
        ft.update(idx, 1);
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}