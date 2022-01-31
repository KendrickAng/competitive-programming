#pragma GCC optimize("O3")
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
    void reset() {
        tree.assign(size, 0);
    }
};

ll countLte(FenwickTree &ft, vector<ll> &revMapping, unordered_map<ll, int> &revMapping2, ll &toFind) {
    if (revMapping2.find(toFind) != revMapping2.end()) {
        return ft.rsq(revMapping2[toFind]);
    }

    auto it = upper_bound(revMapping.begin(), revMapping.end(), toFind);
    if (it == revMapping.begin() && toFind < *it) return 0;
    if (it != revMapping.begin()) it--;
    int idx = (it - revMapping.begin()) + 1;
    // cout << "toFind " << toFind << " idx " << idx << " count " << ft.rsq(idx) << endl;

    return ft.rsq(idx);
}

void solve() {
    int n, q; scanf("%d%d", &n, &q);
    
    // read input and create cumulative sum
    ll sofar = 0;
    vector<ll> sum;
    set<ll> sumCopy;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        sofar += tmp;
        sum.push_back(sofar);

        // for coordinate compression
        sumCopy.insert(sofar);
    }

    // create coordinate mappings
    unordered_map<ll, int> revMapping2; revMapping2.reserve(sumCopy.size());
    vector<ll> revMapping;
    // map<ll, int> revMapping;
    int id = 1;
    for (ll num: sumCopy) {
        revMapping.push_back(num);
        revMapping2[num] = id++;
    }

    // prepare compressed fenwick tree
    FenwickTree ft(n+1);

    // answer queries
    bool first = true;
    for (int i = 0; i < q; i++) {
        ll k; scanf("%lld", &k);
        ll ans = 0;

        // count how many sum[i] st sum[i] <= sum[j] - k, i < j
        for (int j = 0; j < sum.size(); j++) {
            ll toFind = sum[j] - k;

            ans += countLte(ft, revMapping, revMapping2, toFind);
            if (sum[j] >= k) ans++;

            // update fenwick tree
            int ftIdx = revMapping2[sum[j]];
            ft.update(ftIdx, 1);
        }

        if (first) first = false;
        else printf(" ");
        printf("%lld", ans);

        ft.reset();
    }
    printf("\n");
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}