#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto low = std::lower_bound(arr.begin(), arr.end(), l-arr[i]) - arr.begin();
        auto high = std::upper_bound(arr.begin(), arr.end(), r-arr[i]) - arr.begin();
        // youre v[i] is counted in the range between L and R which you need to remove
        int L = l - arr[i];
        int R = r - arr[i];
        if (L <= arr[i] && arr[i] <= R) {
            ans--;
        }     
        ans += high - low;
    }
    cout << ans/2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}