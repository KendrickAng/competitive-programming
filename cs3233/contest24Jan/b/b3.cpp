
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define LSOne(S) ((S) & -(S))
#define DEBUG false
#define debug(x) {if (DEBUG) {cout << "line " << __LINE__ << ": " << x << endl;}}
#define var(x) {cout << #x << " = " << x << " " << endl;}

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

int ftIdx(int i) {
    return i + 1;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    FenwickTree ft(n+10);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // create cumulative sum array
    ll sum = 0;
    vector<ll> cumSum(n);
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        cumSum[i] = sum;
    }

    // ft has one instance of 0
    ft.update(ftIdx(0), 1);

    // fenwick data compression
    // unordered_map<int, int> revMapping; revMapping.reserve(n);
    // vector<int> revMapping;
    // for (int i = 1; i <= n; i++) {
    //     ll num = cumSum[i-1];
    //     // revMapping[num] = i;
    //     revMapping.push_back(num);
    // }

    // answer queries
    bool first = true;
    for (int i = 0; i < q; i++) {
        ll k; cin >> k;
        ll ans = 0;
        // cout << "now solving for " << k << endl;
        for (int j = 0; j < cumSum.size(); j++) {
            // sum[i] <= sum[5] - k
            ll toFind = cumSum[j] - k;
            // map it to an equal value, or the next smallest value we have
            auto it = upper_bound(cumSum.begin(), cumSum.end(), toFind);
            if (it == cumSum.begin() && (toFind < *it)) {
                // trying to find too small a number, do nothing
            } else {
                // +1 to convert back to 1-indexed
                it--;
                int idx = ftIdx(it - cumSum.begin());
                cout << "tofind " << toFind << " idx " << idx << " rsq " << ft.rsq(idx) << endl;                
                ans += ft.rsq(idx);
            }
            ft.update(ftIdx(j+1), 1);
        }

        if (first) first = false;
        else cout << ' ';
        cout << ans;
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}