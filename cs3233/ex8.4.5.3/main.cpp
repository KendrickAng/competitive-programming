#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge; // TODO: store u, v !!
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18; // large enough

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL; // AL[u] stores index of neighbouring edges instead!!
    vi d; // distance array
    vi last; // last visited array, for optimization
    vector<ii> p;

    unordered_map<int, unordered_map<int, int>> edgeMap;

    int start; // start node
    int end; // end node
    bool done = false; // have we run a single instance of max flow?

    bool BFS(int s, int t) { // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1}); // record BFS sp tree
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break; // stop as sink t reached
            for (auto &idx : AL[u]) {                            // explore neighbors of u
                auto &[v, cap, flow] = EL[idx];                  // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))            // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1; // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF) { // send one flow from s->t
        if (s == t) return f; // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]); // back edge
        rflow -= pushed;                   // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF) { // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue; // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]); // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                      // safeguard: no self loop
        EL.emplace_back(v, w, 0);                // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);          // remember this index
        edgeMap[u][v] = EL.size()-1;
        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size() - 1);          // remember this index
        edgeMap[v][u] = EL.size()-1;
    }

    ll edmonds_karp(int s, int t) {
        start = s; end = t;
        ll mf = 0;                      // mf stands for max_flow
        while (BFS(s, t)) {             // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0) break;          // if f == 0, stop
            mf += f;                    // if f > 0, add to mf
        }
        done = true;
        return mf;
    }

    ll dinic(int s, int t) {
        start = s; end = t;
        ll mf = 0;                      // mf stands for max_flow
        while (BFS(s, t)) {             // an O(V^2*E) algorithm
            last.assign(V, 0);          // important speedup
            while (ll f = DFS(s, t))    // exhaust blocking flow
                mf += f;
        }
        done = true;
        return mf;
    }

    // returns edges used in the maximum flow, sorted by (u, v, flow)
    vector<tuple<int,int,int>> maxFlowEdges() {
        vector<tuple<int,int,int>> ret;
        for (int u = 0; u < V; u++) {
            for (int eIdx: AL[u]) { 
                auto &[v, cap, flow] = EL[eIdx];
                if (flow > 0) ret.push_back({ u, v, flow });
            }
        }
        return ret;
    }

    // returns all edges (u, v) used in the min cut
    vector<int> minCutS() {
        if (!done) throw "max flow not yet run";
        // perform bfs, return edges w/ non-positive weighted edges in the residual graph
        vector<int> nodes;
        vector<int> seen(V, false);
        queue<int> q;
        q.push(start);
        seen[start] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            nodes.push_back(u);

            // iterate neighbours of the RESIDUAL GRAPH
            for (int eIdx: AL[u]) {
                auto &[v, cap, flow] = EL[eIdx];
                if (cap-flow <= 0 || seen[v]) continue;
                seen[v] = true;
                q.push(v);
            }
        }

        return nodes;
    }

    vector<pair<int,int>> minCutEdges() {
        if (!done) throw "max flow not yet run";
        // perform bfs, return edges w/ non-positive weighted edges in the residual graph
        vector<pair<int,int>> edges;
        vector<int> seen(V, false);
        queue<int> q;
        q.push(start);
        seen[start] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();

            // iterate neighbours of the RESIDUAL GRAPH
            for (int eIdx: AL[u]) {
                auto &[v, cap, flow] = EL[eIdx];
                if (cap-flow <= 0) edges.push_back({u, v});

                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
            }
        }

        return edges;
    }

    void print() {
        for (int u = 0; u < V; u++) {
            for (int eIdx: AL[u]) { 
                auto &[v, cap, flow] = EL[eIdx];
                cout << u << " -> " << v << " cap: " << cap << " flow: " << flow << endl;
            }
        }
    }

    edge &getEdge(int u, int v) {
        if (edgeMap.find(u) == edgeMap.end() || edgeMap[u].find(v) == edgeMap[u].end())
            throw "no such edge!";
        return EL[edgeMap[u][v]];
    }
};

void solve() {
    int n = 4;
    max_flow mf(n);
    mf.add_edge(0, 1, 5);
    mf.add_edge(0, 2, 4);
    mf.add_edge(1, 3, 5);
    mf.add_edge(2, 3, 4);

    int u = 0;
    int v = 1;
    auto &[tmp, cap, flow] = mf.getEdge(u, v);
    cout << "BEFORE: u: " << u << " v: " << v << " cap: " << cap << " flow: " << flow << endl;

    mf.dinic(0, 3);

    auto &[tmp2, cap2, flow2] = mf.getEdge(u, v);
    cout << "AFTER: u: " << u << " v: " << v << " cap: " << cap2 << " flow: " << flow2 << endl;

    cap2 = 10;
    auto &[tmp3, cap3, flow3] = mf.getEdge(u, v);
    cout << "UPDATE: u: " << u << " v: " << v << " cap: " << cap3 << " flow: " << flow3 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}