#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,bool>>> adjList;
vector<int> visited;
vector<int> marked;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(int u, bool hasBug) {
    //cout << u << endl;
    int forced = 0;
    int optional = 0;
    visited[u] = true;
    for (auto &[v, isForced]: adjList[u]) {
        if (isForced) {
            forced++;
        } else {
            optional++;
        }

        if (visited[v]) continue;

        if (isForced) {
            dfs(v, hasBug);
        } else if (hasBug) { // only take optional edge if has bug
            dfs(v, false);
        }
    }

    if (forced > 0 && optional > 0) { // both forced and optional neighbours
        // do nth
    } else if (forced > 0) { // only forced neighbours
        // do nothing
    } else if (optional > 0) { // only optional neighbours
        marked[u] = 1;
    } else { // no outgoing neighbours
        marked[u] = 1;
    }
}

void print()  {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " : ";
        for (auto &[v, isForced]: adjList[i]) {
            cout << "(" << v << "," << isForced << ")" << " ";
        }
        cout << endl;
    }
}

void printMarked() {
    for (int i = 0; i < marked.size(); i++) {
        if (marked[i] > 0) cout << i << " ";
    }
    cout << endl;
}

int main() {
    fast();

    // read input
    int n, m; cin >> n >> m;
    adjList.assign(n+1, vector<pair<int,bool>>());
    visited.assign(n+1, false);
    marked.assign(n+1, 0);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (u > 0) { // not forced edge
            adjList[u].push_back({v,false});
        } else { // forced edge
            adjList[abs(u)].push_back({v,true});
        }
    }

    for (int i = 0; i < adjList.size(); i++) {
        sort(adjList[i].begin(), adjList[i].end(), [](pair<int,bool> &u, pair<int,bool> &v) {
            if (u.second && v.second) {
                return u.first < v.first;
            } else if (u.second) {
                return true;
            } 
            return false;
        });
    }


    //print();
    // modified dfs
    dfs(1, true);

    //printMarked();

    int ans = 0;
    for (int i = 0; i < marked.size(); i++) {
        ans += marked[i];
    }
    cout << ans << endl;
}