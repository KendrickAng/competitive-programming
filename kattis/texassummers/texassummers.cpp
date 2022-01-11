#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> coords;
vector<vector<pair<int,int>>> adjList;
vector<int> dist;
vector<int> parent;
int inf = 1e9;
int n;

double calcDist(int ux, int uy, int vx, int vy) {
    int x = ux - vx;
    int y = uy - vy;
    return (x * x) + (y * y);
}

void printPath(int u, vector<int> &path) {
    if (u == -1) return;
    printPath(parent[u], path);
    if (u != 0 && u != n-1) path.push_back(u);
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({x, y});
    }
    cin >> x >> y; // starting coord
    coords.insert(coords.begin(), {x, y});
    cin >> x >> y; // ending coord
    coords.push_back({x, y});

    n = n + 2; // added two nodes

    // generate complete graph
    adjList.assign(n, vector<pair<int,int>>());
    for (int u = 0; u < n; u++) {
        for (int v = u+1; v < n; v++) {
            auto [ux, uy] = coords[u];
            auto [vx, vy] = coords[v];
            double weight = calcDist(ux, uy, vx, vy);
            adjList[u].push_back({ v, weight });
            adjList[v].push_back({ u, weight });
        }
    }

    // djikstra's
    dist.assign(n, inf);
    parent.assign(n, -1);
    dist[0] = 0;
    
    set<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(dist[i], i);
    }

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        
        // iterate and relax neighbours
        for (auto &[v, w]: adjList[u]) {
            if (dist[u] + w >= dist[v]) continue; // cant relax
            pq.erase(pq.find({ dist[v], v })); // relax target node
            dist[v] = dist[u] + w;
            parent[v] = u;
            pq.emplace(dist[v], v);
        }
    }

    // reconstruct path
    vector<int> path;
    printPath(n-1, path);
    if (path.empty()) {
        cout << "-" << endl;
    } else {
        for (int node: path) {
            cout << node-1 << endl; // since we made node 0,0 as first node
        }
    }
}