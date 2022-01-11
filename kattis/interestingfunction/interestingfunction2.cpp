#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    long long ans = 0;
    while (l != 0 || r != 0) {
        ans += r - l;
        l /= 10;
        r /= 10;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();

    }
}