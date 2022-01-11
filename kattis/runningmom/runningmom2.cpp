#include <bits/stdc++.h>

using namespace std;

enum {
    UNEXPLORED,
    EXPLORING,
    EXPLORED,
};

unordered_map<string,vector<string>> adjList;
unordered_map<string,string> dfs_parent;
unordered_map<string,int> dfs_num;
unordered_set<string> hasCycle;

void fast() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void cycleCheck(const string &node) {
    dfs_num[node] = EXPLORING;

    for (string &neighbour: adjList[node]) {
        if (dfs_num[neighbour] == UNEXPLORED) {
            // normal exploration
            dfs_parent[neighbour] = node;
            cycleCheck(neighbour);
        } else if (dfs_num[neighbour] == EXPLORING) {
            // cycle found
            string tmp = node;
            while (tmp != neighbour) {
                hasCycle.insert(tmp);
                tmp = dfs_parent[tmp];
            }
            hasCycle.insert(tmp);
        } else {
            // already visited, do nothing
        }
    }

    dfs_num[node] = EXPLORED;
}

int main() {
    // auto start = chrono::high_resolution_clock::now();

    fast();

    int id = 0;
    int n; cin >> n;

    // form the adjacency list
    string u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;

        // assign a number to u, if not yet assigned
        if (adjList.find(u) == adjList.end()) {
            adjList[u] = vector<string>();
            dfs_num[u] = UNEXPLORED;
        }
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = vector<string>();
            dfs_num[v] == UNEXPLORED;
        }
        adjList[u].push_back(v);
    }

    for (const auto&[k, v]: adjList) {
        if (dfs_num[k] == UNEXPLORED) {
            cycleCheck(k);
        }
    }

    // answer queries
    string query;
    while (cin >> query) {
        cout << query << " " << (hasCycle.count(query) ? "safe" : "trapped") << endl;
    }

    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << duration.count() << endl;
}