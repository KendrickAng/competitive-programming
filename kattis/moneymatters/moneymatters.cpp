#include <bits/stdc++.h>

using namespace std;

vector<int> owed;
vector<bool> visited;
vector<vector<int>> adjList;

int dfs(int u) {
    int sum = owed[u];
    visited[u] = true;
    for (int v: adjList[u]) {
        if (visited[v]) continue;
        sum += dfs(v);
    }
    return sum;
}

int main() {
    int n, m; cin >> n >> m;
    owed.assign(n, -1);
    visited.assign(n, false);
    adjList.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> owed[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i) < 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
}