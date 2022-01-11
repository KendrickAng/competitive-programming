#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjList;
vector<int> match;
vector<int> vis;

int Aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R: adjList[L]) {
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;
            return 1; // return true if found an augmenting path
        }
    }
    return 0; // no augmenting path
}

int main() {
    int n, m; cin >> n >> m;

    int V = n + n;
    int VLeft = n; // number of vertices on the left side
    adjList.assign(V, vector<int>());
    
    // read edges
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        v += n; // differentiate people from the books they brought
        adjList[u].push_back(v);
    }

    match.assign(V, -1); // match[r] = l -> vertex l on LHS connected to vertex r on RHS
    int MCBM = 0;
    for (int L = 0; L < VLeft; L++) {
        vis.assign(VLeft, 0);
        MCBM += Aug(L);
    }

    if (MCBM == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}