#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> adjList;
vector<ll> islandToArmy;
vector<ll> visited;
priority_queue<pair<ll,ll>> pq;
ll currArmy = 0;

void expandArmy(ll island) {
    visited[island] = true;
    currArmy += islandToArmy[island];
    for (ll neigh: adjList[island]) {
        // don't revisit nodes
        if (visited[neigh]) {
            continue;
        }

        // check neighbouring army of unvisited nodes
        ll neighArmy = islandToArmy[neigh];
        if (currArmy > neighArmy) { // can overwhelm -> fight
            expandArmy(neigh);
        } else { // else save for next time
            pq.push({ neighArmy, neigh });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll islands, bridges; cin >> islands >> bridges;
    adjList.assign(islands+1, vector<ll>{}); // 1-indexed
    islandToArmy.assign(islands+1, -1); // 1-indexed;
    visited.assign(islands+1, false);

    // read edges
    for (ll i = 0; i < bridges; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // read island army strength
    for (ll i = 1; i <= islands; i++) {
        cin >> islandToArmy[i];
    }

    // traverse
    expandArmy(1);
    while (!pq.empty() and currArmy > islandToArmy[pq.top().second]) {
        ll nextIsland = pq.top().second; pq.pop();
        // if (visited[nextIsland]) continue;
        expandArmy(nextIsland);
    }

    cout << currArmy << endl;
}