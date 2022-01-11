#include <bits/stdc++.h>

using namespace std;

vector<vector<tuple<int,int,int,int>>> adjList;
vector<int> dist; // time
int inf = 1e9;

void solve(int n, int m, int q, int s) {
    adjList.assign(n, vector<tuple<int,int,int,int>>());

    // read in edges
    int u, v, t0, P, d;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t0 >> P >> d;
        adjList[u].push_back({v, t0, P, d});
    }

    // djikstras
    dist.assign(n, inf);
    dist[s] = 0;
    set<pair<int,int>> pq;
    for (int u = 0; u < n; u++) {
        pq.emplace(dist[u], u);
    }

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        //cout << d << " : " << u << endl;
        pq.erase(pq.begin());
        for (auto &[v, t0, P, edgeCost]: adjList[u]) {
            // if P = 0, edge can only be used at time t0 and never again
            if (P == 0 && d > t0) continue;

            // dynamically calculate the next time the edge can be used
            int cost = 0;
            if (d == t0) {
                cost = 0; // just use the edge as-is
            } else if (d < t0) {
                cost = t0 - d; // wait until time t0 to use the edge
            } else {
                // raise the time to the next time we can use the edge
                int intervals = ceil(((double) d - t0) / P);
                cost = t0 + (intervals * P) - d; // added time to take the edge
            }
            // add cost to traverse the edge
            cost += edgeCost;

            if (dist[u] + cost >= dist[v]) continue; // not improving, skip
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + cost;
            pq.emplace(dist[v], v);
        }
    }

    // answer queries
    int query;
    for (int i = 0; i < q; i++) {
        cin >> query;
        if (dist[query] == inf) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[query] << endl;
        }
    }
}

int main() {
    int n, m, q, s; cin >> n >> m >> q >> s;
    while (!(n == 0 && m == 0 && q == 0 && s == 0)) {
        solve(n, m, q, s);
        cin >> n >> m >> q >> s;
    }
}