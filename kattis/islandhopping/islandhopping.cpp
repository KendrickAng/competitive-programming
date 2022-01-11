#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    private:
    vector<int> parent;
    vector<int> size; // for union by rank
    
    public:
    UnionFind() {
        parent = vector<int>();
        size = vector<int>();
    }
    void add(int item) {
        if (item != parent.size() || item != size.size()) {
            throw "error";
        }
        parent.push_back(item); // initialize parent to itself
        size.push_back(1);
    }
    int find(int item) {
        while (item != parent[item]) {
            // path compression
            parent[item] = parent[parent[item]];
            item = parent[item];
        }
        return item;
    }
    void unionSet(int p, int q) {
        int rp = find(p);
        int rq = find(q);
        if (rp == rq) return;
        // union by rank attaches the smaller tree to the larger tree
        if (size[rp] > size[rq]) swap(rp, rq); // rp < rq
        parent[rp] = rq;
        size[rq] += size[rq];
    }
};


double distance(double ux, double uy, double vx, double vy) {
    double a = ux - vx;
    double b = uy - vy;
    return sqrt(a*a + b*b);
}

void solve() {
    int islands; cin >> islands;
    vector<pair<double,double>> coords(islands);
    vector<tuple<double,int,int>> edgeList;
    UnionFind uf;

    double x, y;
    for (int i = 0; i < islands; i++) {
        cin >> x >> y;
        coords[i] = {x, y};
        uf.add(i);
    }

    // form edges
    for (int u = 0; u < islands; u++) {
        for (int v = u+1; v < islands; v++) {
            auto [ux, uy] = coords[u];
            auto [vx, vy] = coords[v];
            double weight = distance(ux, uy, vx, vy);
            edgeList.push_back({weight, u, v});
        }
    }

    // kruskals
    sort(edgeList.begin(), edgeList.end());
    double mst_cost = 0;
    int num_taken = 0;
    for (auto &[w, u, v]: edgeList) {
        if (uf.find(u) == uf.find(v)) continue;
        mst_cost += w;
        uf.unionSet(u, v);
        num_taken++;
        if (num_taken == islands-1) break; // minor optimization
    }

    cout << fixed << setprecision(15) << mst_cost << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}