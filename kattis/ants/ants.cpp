#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int l, n; cin >> l >> n;
    vector<int> pole(n);
    for (int i = 0; i < n; i++) cin >> pole[i];
    int minn = -1;
    int maxx = -1;
    for (int i: pole) {
        minn = max(minn, min(i, l-i));
        maxx = max(maxx, max(i, l-i));
    }
    cout << minn << " " << maxx << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}