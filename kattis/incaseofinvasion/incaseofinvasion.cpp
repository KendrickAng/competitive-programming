#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using edge = tuple<int, ll, ll>; // v, capacity, flow
using vi = vector<int>;
using ii = pair<int, int>;

const ll INF = 1e18; // large enough

struct pairHash {
    size_t operator()(const ii& pr) const {
        return ((size_t) pr.first + 1e6) * 1e8 + ((size_t) pr.second + 1e6);
    }
};

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL; // AL[u] stores index of neighbouring edges instead!!
    vi d; // distance array
    vi last; // last visited array, for optimization
    vector<ii> p;

    unordered_map<ii, int, pairHash> edgeMap;

    int S; // start node
    int T; // end node
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

    // ############################### MAXIMUM FLOW ###############################

    ll edmonds_karp(int s, int t) {
        S = s;
        T = t;
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
        S = s;
        T = t;
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

    // ############################### MINIMUM CUT ###############################

    // returns all edges (u, v) used in the min cut
    vector<int> minCutS() {
        if (!done) throw "max flow not yet run";
        // perform bfs, return edges w/ non-positive weighted edges in the residual graph
        vector<int> nodes;
        vector<int> seen(V, false);
        queue<int> q;
        q.push(S);
        seen[S] = true;
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
        q.push(S);
        seen[S] = true;
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

    // ############################### HELPER METHODS ###############################
    
    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                      // safeguard: no self loop
        EL.emplace_back(v, w, 0);                // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);          // remember this index
        edgeMap[{u,v}] = EL.size()-1;
        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size() - 1);          // remember this index
        edgeMap[{v,u}] = EL.size()-1;
    }

    // NOT TESTED splits the specified vertex into two
    int add_vertex_weight(int u, ll w) {
        // generate new index for cloned vertex
        int v = clone_idx(u);
        // move all edges to this new index
        AL[v] = AL[u];
        AL[u].clear();
        // connect u and v with an edge
        add_edge(u, v, w);
        return v;
    }

    // NOT TESTED
    int clone_idx(int idx) {
        int ret = V++; // assume indexes 0 to V are used
        return ret;
    }
    
    edge &getEdge(int u, int v) {
        if (!hasEdge(u, v))
            throw "no such edge!";
        return EL[edgeMap[{u,v}]];
    }

    bool hasEdge(int u, int v) {
        return edgeMap.find({u,v}) != edgeMap.end();
    }

    // for cases where multiple runs of max flow needed for the same graph
    void reset() {
        for (edge &e: EL) {
            auto &[v, capacity, flow] = e;
            flow = 0;
        }
    }

    void setEdgeCapacity(int u, int v, ll w) {
        if (hasEdge(u, v)) {
            auto &[_, capacity, flow] = getEdge(u, v);
            capacity = w;
        }
        if (hasEdge(v, u)) {
            auto &[_, capacity, flow] = getEdge(v, u);
            capacity = w;
        }
    }

    // prints all edges in the max flow graph.
    void print() {
        for (int u = 0; u < V; u++) {
            for (int eIdx: AL[u]) { 
                auto &[v, cap, flow] = EL[eIdx];
                if (cap == 0) continue;
                string uStr = to_string(u);
                string vStr = to_string(v);
                if (u == S) uStr = "S";
                if (u == T) uStr = "T";
                if (v == S) vStr = "S";
                if (v == T) vStr = "T";
                cout << uStr << " -> " << vStr << " cap: " << cap << " flow: " << flow << endl;
            }
        }
        cout << endl;
    }
};

using ll = long long;

int N, M, S;
ll people = 0;
vector<ll> living;
vector<ll> shelters;
vector<ll> shelterCap;
vector<vector<pair<ll, ll>>> adjList;
vector<vector<ll>> shelterToLoc; // time needed

const ll INF2 = 1e18;

bool isOk(ll givenTime) {
    // shelters: [0, S)
    // locations: [S, S+(1<<S)))
    ll V = 2 + S + (1LL << S);
    ll START = V-1;
    ll END = V-2;
    max_flow pr(V);
    
    // initialize composite nodes
    ll total = 0;
    vector<ll> caps((1 << S), 0);
    for (ll i = 0; i < N; i++) {
        ll mask = 0;
        for (ll j = 0; j < S; j++) {
            ll needTime = shelterToLoc[j][i];
            if (needTime <= givenTime) {
                mask |= (1 << j);
            }
        }
        caps[mask] += living[i];
        total += living[i];
    }

    // source to shelters
    for (ll i = 0; i < S; i++) {
        pr.add_edge(START, i, shelterCap[shelters[i]]);
    }

    // locations to sink
    for (ll i = 0; i < (1<<S); i++) {
        ll lid = i + S;
        pr.add_edge(lid, END, caps[i]);

        // shelter to location (if can be reached)
        for (ll j = 0; j < S; j++) {
            if (i & (1 << j)) {
                pr.add_edge(j, lid, INF2);
            }
        }
    }

    ll flow = pr.dinic(START, END);
    // debug(flow, total);
    // pr.print();
    return flow == total;
}

void solve() {
    cin >> N >> M >> S;
    shelters.resize(S); // index to shelter index
    living.resize(N);
    shelterCap.assign(N, 0);
    adjList.assign(N, {});
    shelterToLoc.assign(S, vector<ll>(N, -1));

    // read input
    for (ll i = 0; i < N; i++) {
        cin >> living[i];
        people += living[i];
    }
    for (ll i = 0; i < M; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--; // locations given 1-indexed
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }
    for (ll i = 0; i < S; i++) {
        ll shelterIdx, cap; cin >> shelterIdx >> cap;
        shelterIdx--; // shelters given 1-indexed
        shelters[i] = shelterIdx;
        shelterCap[shelterIdx] = cap;
        // debug(i, shelters[i]);
    }

    // find shortest path from each shelter to all locations
    for (ll i = 0; i < S; i++) {
        ll s = shelters[i];

        // initialize stuff
        vector<ll> dist(N, INF2);
        dist[s] = 0;
        set<pair<ll, ll>> pq;
        for (ll u = 0; u < N; u++) pq.emplace(dist[u], u);
        
        // take pairs by non-decreasing order from s
        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            for (auto &[v, w]: adjList[u]) {
                if (dist[u] + w >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }

        // copy over distances
        for (ll j = 0; j < N; j++) {
            shelterToLoc[i][j] = dist[j];
        }
    }

    // min cost max flow
    ll V = S + N + 2;
    ll START = V-1;
    ll END = V-2;

    ll lo = 0;
    ll hi = 1e14;
    ll last = -1;
    while (lo <= hi) {
        ll mid = lo + ((hi - lo) / 2);
        // debug(lo, mid, hi);
        if (isOk(mid)) { // try a lower time
            hi = mid-1;
            last = mid;
        } else { // need more time
            lo = mid+1;
        }
    }

    cout << last << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}