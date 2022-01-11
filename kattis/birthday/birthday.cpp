#include <bits/stdc++.h>

using namespace std;

enum {
    UNVISITED = -1,
};

vector<vector<int>> adjList;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;

int dfsNumberCounter;
bool hasBridge;

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];
    // iterate neighbours
    for (int v: adjList[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            articulationPointAndBridge(v);

            if (dfs_low[v] > dfs_num[u])
                hasBridge = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update entire dfs subtree
        } else if (v != dfs_parent[u]) {
            // non-trivial cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void solve(int numNodes, int numEdges) {
    dfs_num.assign(numNodes, UNVISITED);
    dfs_low.assign(numNodes, 0);
    dfs_parent.assign(numNodes, -1);
    hasBridge = false;
    dfsNumberCounter = 0;

    // read adjacency list
    adjList.assign(numNodes, vector<int>());
    for (int i = 0; i < numEdges; i++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // find bridges
    for (int u = 0; u < numNodes; u++) {
        if (dfs_num[u] == UNVISITED) {
            articulationPointAndBridge(u);
        }
    }

    if (hasBridge) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int p, c; cin >> p >> c;
    while (p != 0 && c != 0) {
        solve(p, c);
        cin >> p >> c;
    }
}