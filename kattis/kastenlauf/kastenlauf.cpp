#include <bits/stdc++.h>

using namespace std;

int manhattan(int ax, int ay, int bx, int by) {
    return abs(ax - bx) + abs(ay - by);
}

void solve() {
    int n; cin >> n; n += 2;

    // read coordinates
    vector<pair<int,int>> coords;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coords.push_back({x,y});
    }

    // form adj matrix
    vector<vector<int>> am(n, vector<int>(n, 0));

    // fill with beginning edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto [ax, ay] = coords[i];
            auto [bx, by] = coords[j];
            if (manhattan(ax, ay, bx, by) <= 20 * 50) {
                am[i][j] = 1;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << am[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                am[i][j] = am[i][j] || (am[i][k] && am[k][j]);
            }
        }
    }

    if (am[0][n-1]) {
        cout << "happy" << endl;
    } else {
        cout << "sad" << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}