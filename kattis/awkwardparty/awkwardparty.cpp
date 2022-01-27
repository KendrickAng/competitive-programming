#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    unordered_map<int,int> mapping;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (mapping.find(tmp) != mapping.end()) {
            int awkLvl = i - mapping[tmp];
            ans = min(ans, awkLvl);
        }
        mapping[tmp] = i;
    }

    if (ans == INT_MAX) ans = n;
    cout << ans << endl;
}