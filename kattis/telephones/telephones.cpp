#include <bits/stdc++.h>

using namespace std;

bool overlap(int s1, int d1, int s2, int d2) {
    int e1 = s1 + d1; // exclusive
    int e2 = s2 + d2; // exclusive
    return min(e1, e2) > max(s1, s2);
}

void solve(int n, int m) {
    // read in calls
    vector<pair<int,int>> calls(n);
    int src, dest, start, duration;
    for (int i = 0; i < n; i++) {
        cin >> src >> dest >> start >> duration;
        calls.push_back({start, duration});
    }

    // read in durations and answer each query
    int polStart, polDuration;
    for (int i = 0; i < m; i++) {
        cin >> polStart >> polDuration;
        int ans = 0;
        for (auto &[start, duration]: calls) {
            if (overlap(start, duration, polStart, polDuration)) {
                ans ++;
            }
        }
        cout << ans << endl;
    }

}

int main() {
    int n, m; cin >> n >> m;
    while (n != 0 and m != 0) {
        solve(n, m);
        cin >> n >> m;
    }
}