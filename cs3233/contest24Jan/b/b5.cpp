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
};

ll countLte(FenwickTree &ft, map<ll,int> &revMapping, ll toFind) {
    // var(toFind);
    auto it = revMapping.upper_bound(toFind);
    if (it == revMapping.begin() && toFind < it->first) return 0;
    if (it != revMapping.begin()) it--;
    int idx = it->second;
    // cout << "toFind " << toFind << " idx " << idx << " count " << ft.rsq(idx) << endl;

    return ft.rsq(idx);
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    
    // read input and create cumulative sum
    ll sofar = 0;
    vector<ll> sum;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        sofar += tmp;
        sum.push_back(sofar);
    }

    // coordinate compression
    bool addZero = false;
    vector<ll> sumCopy(sum);
    sort(sumCopy.begin(), sumCopy.end());

    // if (sumCopy[0] > 0) addZero = true;
    // if (addZero) sumCopy.insert(sumCopy.begin(), 0);
    
    // for (int i: sumCopy) cout << i << ' '; cout << endl;

    // remove duplicates
    // auto it = unique(sumCopy.begin(), sumCopy.end());
    // sumCopy.resize(distance(sumCopy.begin(), it));

    // create coordinate mappings
    map<ll, int> revMapping;
    for (int i = 1; i <= sumCopy.size(); i++) {
        int num = sumCopy[i-1];
        revMapping[num] = i;
    }

    // for (auto [a, b]: revMapping) {
    //     cout << "num " << a << " idx " << b << endl;
    // }

    // for (int i: sum) cout << i << ' '; cout << endl;

    // answer queries
    bool first = true;
    for (int i = 0; i < q; i++) {
        ll k; cin >> k;
        ll ans = 0;
        // var(k);
        // prepare compressed fenwick tree
        FenwickTree ft(n+1);
        // if (addZero) ft.update(revMapping[0], 1);

        // count how many sum[i] st sum[i] <= sum[j] - k, i < j
        for (int j = 0; j < sum.size(); j++) {
            ll toFind = sum[j] - k;
            // var(toFind);
            // var(j);

            ans += countLte(ft, revMapping, toFind);

            // update fenwick tree
            int ftIdx = revMapping[sum[j]];
            ft.update(ftIdx, 1);
        }

        for (ll num: sum) if (num >= k) ans++;

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