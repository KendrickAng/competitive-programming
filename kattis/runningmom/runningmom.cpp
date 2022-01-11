#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> mapping;
vector<vector<int>> adjList;
unordered_set<int> safe;
unordered_set<int> trapped;

void fast() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool dfs(int u, unordered_set<int> &visiting) {
    visiting.insert(u);
    for (int v: adjList[u]) {
        if (visiting.count(v)) return true; // just reached a cycle
        if (dfs(v, visiting)) return true; // returning from a cycle
    }

    trapped.insert(u); // no cycle found
    visiting.erase(u);
    return false;
}

bool cycleDetected(int u) {
    if (safe.count(u)) return true;
    if (trapped.count(u)) return false;

    unordered_set<int> visiting;
    bool hasCycle = dfs(u, visiting);
    
    // update safe
    for (int node: visiting) {
        safe.insert(node);
    }
    
    return hasCycle;
}

int main() {
    // auto start = chrono::high_resolution_clock::now();

    fast();

    int cities = 0;
    int n; cin >> n;

    // form the adjacency list
    string u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;

        // assign a number to u, if not yet assigned
        if (mapping.find(u) == mapping.end()) {
            mapping[u] = cities++;
            adjList.push_back(vector<int>());
        }
        // assign a number to v, if not yet assigned
        if (mapping.find(v) == mapping.end()) {
            mapping[v] = cities++;
            adjList.push_back(vector<int>());
        }

        int uid = mapping[u];
        int vid = mapping[v];
        adjList[uid].push_back(vid);
    }

    // answer queries
    string query;
    while (cin >> query) {
        int id = mapping[query];
        cout << query << " ";
        if (cycleDetected(id)) {
            cout << "safe" << endl;
        } else {
            cout << "trapped" << endl;
        }
    }

    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << duration.count() << endl;
}