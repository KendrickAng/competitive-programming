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
using ii = pair<int, int>;
using edge = tuple<int, ll, ll>; // v, capacity, flow
using vi = vector<int>;

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

    // ############################### MAXIMUM FLOW ###############################

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

    // ############################### MINIMUM CUT ###############################

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
                // ignore redundant edges
                if (cap <= 0) continue;
                cout << u << " -> " << v << " cap: " << cap << " flow: " << flow << endl;
            }
        }
    }
};

int N;
vector<int> teamPts;
vector<vector<char>> results;

bool canWin(int currTeam) {
    set<ii> games;
    int ourMaxPts = teamPts[currTeam];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // possible match the current team can win
            if (i < j) {
                if (results[i][j] == '.') {
                    if (i == currTeam || j == currTeam) {
                        ourMaxPts += 2;
                    } else {
                        games.insert({i, j});
                    }
                }
            }
        }
    }

    // construct max flow graph
    int V = 1 + games.size() + N + 1;
    max_flow mf(V);

    int id = N; // 0 to N reserved for teams
    int source = id++;
    int sink = id++;
    // debug(source, sink);
    
    // source to games, games to teams
    for (auto [teamA, teamB]: games) {
        int mid = id++;
        mf.add_edge(source, mid, 2);
        mf.add_edge(mid, teamA, 2);
        mf.add_edge(mid, teamB, 2);
    }
    // teams to sink
    for (int teamId = 0; teamId < N; teamId++) {
        if (teamId == currTeam) continue;

        int buffer = ourMaxPts - teamPts[teamId];
        if (buffer < 0) return false;
        mf.add_edge(teamId, sink, buffer);
    }

    ll flow = mf.dinic(source, sink);
    // mf.print();
    // debug(currTeam, ourMaxPts, flow);
    // debug(games);

    return flow == (2 * games.size());
}

void solve() {
    cin >> N;
    teamPts.assign(N, 0);
    results.assign(N, vector<char>(N));

    // read match results
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> results[i][j];
        }
    }

    // count points for each team
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // competitors don't play themselves
            // also all points are double to prevent 0.5
            if (i < j) {
                if (results[i][j] == 'x') continue;
                else if (results[i][j] == '0') teamPts[j] += 2;
                else if (results[i][j] == '1') teamPts[i] += 2;
                else if (results[i][j] == 'd') {
                    teamPts[i] += 1;
                    teamPts[j] += 1;
                }
            }
        }
    }

    vector<int> ans;
    for (int currTeam = 0; currTeam < N; currTeam++) {
        // look through information
        if (canWin(currTeam)) ans.push_back(currTeam);
    }

    for (int i: ans) cout << i+1 << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}