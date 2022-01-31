#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, l; cin >> n >> h >> l;
    vector<int> hiMovies(h);
    for (int i = 0; i < h; i++) {
        cin >> hiMovies[i];
    }

    // read edges
    vector<vector<int>> adjList(n, vector<int>());
    for (int i = 0; i < l; i++) {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // bfs
    vector<int> dist(n, 1e9);
    for (int start: hiMovies) {
        unordered_set<int> seen;
        seen.insert(start);
        queue<ii> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto [id, horrorIdx] = q.front(); q.pop();
            dist[id] = min(dist[id], horrorIdx);
            for (int neigh: adjList[id]) {
                if (seen.count(neigh)) continue;
                seen.insert(neigh);
                q.push({neigh, horrorIdx + 1});
            }
        }
    }

    for (int i: hiMovies) dist[i] = 0;
    // for (int i: dist) cout << i << " "; cout << endl;
    int idx = max_element(dist.begin(), dist.end()) - dist.begin();
    cout << idx << endl;
}