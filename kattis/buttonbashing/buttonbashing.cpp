#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> neighbours(n);
    for (int i = 0; i < n; i++) {
        cin >> neighbours[i];
    }

    // bfs - (cooking time, button presses)
    int minPresses = 1e9;
    int minSeconds = 1e9;
    queue<pair<int,int>> q;
    vector<bool> seen(3601, false);

    q.push({0,0});
    seen[0] = true;
    while (!q.empty()) {
        auto &[cookTime, presses] = q.front();
        q.pop();

        // found exact answer - can exit
        if (cookTime == t) {
            minSeconds = cookTime;
            minPresses = presses;
            break;
        }
        // found a candidate answer - continue
        if (cookTime >= t && cookTime < minSeconds) {
            minSeconds = cookTime;
            minPresses = presses;
        }

        for (int delta: neighbours) {
            int newCookTime = cookTime + delta;
            int newPresses = presses + 1;
            if (newCookTime < 0) newCookTime = 0;
            if (newCookTime > 3600) newCookTime = 3600;
            // if already seen, we can't get less button presses - skip this 
            if (seen[newCookTime]) continue;
            seen[newCookTime] = true;
            q.push({newCookTime, newPresses});
        }
    }
    cout << minPresses << " " << minSeconds - t << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}