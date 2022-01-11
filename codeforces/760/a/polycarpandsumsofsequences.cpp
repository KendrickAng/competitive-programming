#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> nums(7);
    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
    }
    cout << nums[0] << " " << nums[1] << " " << nums[6]-nums[0]-nums[1] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}