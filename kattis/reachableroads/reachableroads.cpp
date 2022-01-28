#include <bits/stdc++.h>

using namespace std;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

void dfs(vvi &adjList, vb &seen, int u) {
    seen[u] = true;
    for (int v: adjList[u]) {
        if (!seen[v]) dfs(adjList, seen, v);
    }
}

void solve() {
    int nodes, edges; cin >> nodes >> edges;
    vvi adjList(nodes, vector<int>());
    vb seen(nodes, false);
    for (int i = 0; i < edges; i++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < nodes; i++) {
        if (!seen[i]) {
            dfs(adjList, seen, i);
            ans++;
        }
    }
    cout << ans-1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}