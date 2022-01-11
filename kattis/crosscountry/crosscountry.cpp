#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adjList;
vector<int> dist;
int inf = 1e9;

int main () {
    int n, s, t; cin >> n >> s >> t;
    adjList.assign(n, vector<pair<int,int>>());

    int duv;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n ; v++) {
            cin >> duv;
            if (u == v) continue;
            adjList[u].push_back({ v, duv });
        }
    }

    dist.assign(n, inf);

    set<pair<int,int>> pq;
    dist[s] = 0;
    for (int u = 0; u < n; u++) {
        pq.insert({ dist[u], u });
    }

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [v, weight]: adjList[u]) {
            if (dist[u] + weight >= dist[v]) continue;
            pq.erase(pq.find({ dist[v], v }));
            dist[v] = dist[u] + weight;
            pq.insert({ dist[v], v });
        }
    }

    cout << dist[t] << endl;
}