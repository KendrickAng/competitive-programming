#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(int n) {
    int v, m, d;
    vector<int> marbles(n+1, 0);
    vector<int> parent(n+1, -1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v >> m >> d;
        marbles[v] = m;
        indegree[v] = d;
        for (int j = 0; j < d; j++) {
            int child; cin >> child;
            parent[child] = v;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    // bfs variant
    int ans = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();

        int owed = marbles[node]-1;
        ans += abs(owed);
        int parNode = parent[node];
        if (parNode != -1) {
            marbles[parNode] += owed;
        }

        // add to queue if its now a leaf
        indegree[parNode]--;
        if (indegree[parNode] == 0) {
            q.push(parNode);
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
    }
    return 0;
}