#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int d, n, k; cin >> d >> n >> k;
    vector<tuple<int,int,int>> arr;
    for (int i = 0; i < n; i++) {
        int happiness, start, end; cin >> happiness >> start >> end;
        arr.push_back({ happiness, start, end });
    }

    sort(arr.rbegin(), arr.rend());

    int ans = -1;
    for (int day = 1; day <= d; day++) { // try all possible days
        int tmpAns = 0;
        int numPicked = 0;
        for (auto [happiness, start, end]: arr) {
            if (start <= day && day <= end) {
                numPicked++;
                tmpAns += happiness;
                if (numPicked == k) {
                    break;
                }
            }
        }
        ans = max(ans, tmpAns);
    }

    printf("Case #%d: %d\n", t, ans);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}