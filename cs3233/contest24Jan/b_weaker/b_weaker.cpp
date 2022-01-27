#include <bits/stdc++.h>

using namespace std;
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
    
    int n; cin >> n;
    FenwickTree ft(n+10);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arrCopy(arr);
    sort(arrCopy.begin(), arrCopy.end());

    vector<int> mapping(n+10);
    unordered_map<int, int> revMapping; revMapping.reserve(n);
    for (int i = 1; i <= n; i++) {
        int num = arrCopy[i-1];
        mapping[i] = num;
        revMapping[num] = i;
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