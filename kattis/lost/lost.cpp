#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> mapping;
vector<vector<pair<int,int>>> adjList;
vector<int> depth; // first depth where the node is seen
vector<int> cost; // cost to translate from english (taking into account previous work)
int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    adjList.assign(n+1, vector<pair<int,int>>()); // for English too
    depth.assign(n+1, inf);
    cost.assign(n+1, inf);

    // read in nodes and assign mappings
    int id = 0;
    mapping["English"] = id++;
    for (int i = 0; i < n; i++) {
        string lang; cin >> lang;
        mapping[lang] = id++;
    }

    // read in edges
    for (int i = 0; i < m; i++) {
        string a, b;
        int cost;
        cin >> a >> b >> cost;
        int aIdx = mapping[a];
        int bIdx = mapping[b];
        adjList[aIdx].push_back({bIdx,cost});
        adjList[bIdx].push_back({aIdx, cost});
    }

    // bfs - (node idx, edge weight taken to reach node, depth where node was seen)
    queue<tuple<int,int,int>> q;
    int currDepth = 0;
    int eIdx = mapping["English"];
    q.push({eIdx, 0, 0});
    cost[eIdx] = 0;
    depth[eIdx] = currDepth;

    while (!q.empty()) {
        currDepth++;
        int limit = q.size();
        for (int i = 0; i < limit; i++) {
            auto [node, weight, seenDepth] = q.front(); q.pop();
            //cout << node << " " << weight << " " << seenDepth << endl;

            for (auto [nxt, nxtWeight]: adjList[node]) {
                if (depth[nxt] == inf || depth[nxt] == currDepth) {
                    cost[nxt] = min(cost[nxt], nxtWeight);
                    depth[nxt] = currDepth;
                    q.push({nxt, nxtWeight, currDepth});
                }
            }
        }
    }

    // for (int c: cost) cout << c << " ";
    // cout << endl;

    long total = 0;
    for (int c: cost) {
        if (c == inf) {
            cout << "Impossible" << endl;
            return 0;
        }
        total += c;
    }
    cout << total << endl;
}