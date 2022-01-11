#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;

void solve(int n, int m, int q) {
    vector<vector<int>> am(n, vector<int>(n, inf));
    
    // main diagonal set to 0
    for (int i = 0; i < n; i++) {
        am[i][i] = 0;
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        am[u][v] = min(am[u][v], w); // prefer negative weights
    }
    
    // floyd warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][k] < inf and am[k][j] < inf) {
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
                }
                // if am[0][1] == -3 and am[1][2] == inf and am[0][2] == inf (no path)
                // i.e [0] --(-3)--> [1]        [2]
                // am[0][2] = min(inf, inf -3) - WRONG! Correct answer should be inf since there is no path from 0 to 2.
                // am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
            }
        }
    }

    // find all undefined (infinitely negative) paths
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; am[i][j] != -inf and k < n; k++) {
                if (am[i][k] != inf and am[k][j] != inf and am[k][k] < 0) {
                    am[i][j] = -inf;
                }
            }
        }
    }

    // answer queries
    int u, v;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        if (am[u][v] == inf) {
            cout << "Impossible" << endl;
        } else if (am[u][v] == -inf) {
            cout << "-Infinity" << endl;
        } else {
            cout << am[u][v] << endl;
        }
    }

    // print a blank line after each test case
    cout << endl;
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    while (!(n == 0 and m == 0 and q == 0)) {
        solve(n, m, q);
        cin >> n >> m >> q;
    }
}