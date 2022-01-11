#include <functional>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Edge {
    int cost;
    int from;
    int to;
};

int main() {
    int n; cin >> n;
    vector<vector<int>> adjMatrix{};
    adjMatrix.resize(n);
    for (vector<int> &v: adjMatrix) {
        v.resize(n);
    }
    unordered_map<int, vector<Edge>> adjList{};

    // read adj matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            adjMatrix[i][j] = tmp;
        }
    }

    // convert to adj list
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (adjMatrix[r][c] != 0) {
                Edge e = Edge{adjMatrix[r][c], r, c};
                adjList[r].push_back(e);
            }
        }
    }

    // prims ElogE algorithm
    auto cmp = [](Edge l, Edge r) { return l.cost > r.cost; };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);
    vector<bool> visited{};
    visited.resize(n);
    vector<Edge> ans{};

    // init
    visited[0] = true;
    for (auto &e: adjList[0]) {
        q.push(e);
    }

    while (!q.empty() && ans.size() != n-1) {
        Edge edge = q.top(); q.pop();
        if (visited[edge.to]) {
            continue;
        } else {
            ans.push_back(edge);
            visited[edge.to] = true;
            for (auto &neighbour: adjList[edge.to]) {
                if (!visited[neighbour.to]) {
                    q.push(neighbour);
                }
            }
        }
    }

    // int cost = 0;
    for (auto &e: ans) {
        // cost += e.cost;
        cout << e.from+1 << " " << e.to+1 << endl;
    }
    // cout << cost;
}
