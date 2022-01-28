#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    
    // read in input
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // sliding window
    int maxTree = INT_MIN;
    int minTree = INT_MAX;
    multiset<int> window;
    int l = 0;
    int r = 0;
    int ans = INT_MAX;
    while (r < n) {
        if (r < k) {
            window.insert(arr[r++]);
        } else {
            ans = min(ans, abs(*window.begin()-*window.rbegin()));
            window.erase(window.find(arr[l++]));
            window.insert(arr[r++]);
        }
    }
    ans = min(ans, abs(*window.begin()-*window.rbegin()));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}