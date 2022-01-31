#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

vector<vector<iii>> adjList;
vector<vector<iii>> pred;
vector<ll> dist;

const int INF = 1e9;
int id = 0;

ll getPaths(int u, unordered_set<int> &seen) {
    if (u == 0) return 0;
    ll ans = 0;
    for (auto [v, weight, edgeId]: pred[u]) {
        if (seen.find(edgeId) != seen.end()) continue;
        // cout << u << ' ' << v << ' ' << weight << endl;
        seen.insert(edgeId);
        ans += weight + getPaths(v, seen);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges; cin >> nodes >> edges;
    pred.assign(nodes, vector<iii>{});
    adjList.assign(nodes, vector<iii>{});
    for (int i = 0; i < edges; i++) {
        int u, v, weight; cin >> u >> v >> weight;
        adjList[u].push_back({weight, v, id});
        adjList[v].push_back({weight, u, id});
        id++;
    }

    // sort by increasing edge weight
    // for (int i = 0; i < nodes; i++) {
    //     sort(adjList[i].begin(), adjList[i].end());
    // }

    // djikstra
    set<ii> pq;
    dist.assign(nodes, INF); 
    dist[0] = 0;
    for (int i = 0; i < dist.size(); i++) {
        pq.insert({dist[i], i});
    }

    while (!pq.empty()) {
        auto [distance, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [weight, v, edgeId]: adjList[u]) {
            if (dist[u] + weight < dist[v]) {
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + weight;
                pq.insert({dist[v], v});
                pred[v].clear();
                pred[v].push_back({u, weight, edgeId});
            } else if (dist[u] + weight == dist[v]) {
                pred[v].push_back({u, weight, edgeId});
            }
        }
    }

    unordered_set<int> seen;
    cout << getPaths(nodes-1, seen) * 2 << endl;
}