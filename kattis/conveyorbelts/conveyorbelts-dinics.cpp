#include <bits/stdc++.h>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef tuple<int, ll, ll> edge; // TODO: store u, v !!
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18; // large enough

class max_flow
{
private:
    int V;
    vector<edge> EL;
    vector<vi> AL; // AL[u] stores index of neighbouring edges instead!!
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t)
    { // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1}); // record BFS sp tree
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t)
                break; // stop as sink t reached
            for (auto &idx : AL[u])
            {                                                    // explore neighbors of u
                auto &[v, cap, flow] = EL[idx];                  // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))            // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1; // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF)
    { // send one flow from s->t
        if (s == t)
            return f; // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]); // back edge
        rflow -= pushed;                   // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF)
    { // traverse from s->t
        if ((u == t) || (f == 0))
            return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i)
        { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1)
                continue; // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow)))
            {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]); // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    max_flow(int initialV) : V(initialV)
    {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true)
    {
        if (u == v)
            return;                              // safeguard: no self loop
        EL.emplace_back(v, w, 0);                // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);          // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size() - 1);          // remember this index
    }

    ll edmonds_karp(int s, int t)
    {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t))
        {                               // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0)
                break; // if f == 0, stop
            mf += f;   // if f > 0, add to mf
        }
        return mf;
    }

    ll dinic(int s, int t)
    {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t))
        {                            // an O(V^2*E) algorithm
            last.assign(V, 0);       // important speedup
            while (ll f = DFS(s, t)) // exhaust blocking flow
                mf += f;
        }
        return mf;
    }

    vector<tuple<int,int,int>> usedEdges() {
        vector<tuple<int,int,int>> ret;
        for (int u = 0; u < V; u++) {
            for (int eIdx: AL[u]) { 
                auto &[v, cap, flow] = EL[eIdx];
                if (flow > 0) ret.push_back({ u, v, flow });
            }
        }
        return ret;
    }

    void print() {
        for (int u = 0; u < V; u++) {
            for (int eIdx: AL[u]) { 
                auto &[v, cap, flow] = EL[eIdx];
                cout << u << " -> " << v << " cap: " << cap << " flow: " << flow << endl;
            }
        }
    }
};

int N, K, M;

// n is 1-indexed, k is 0-indexed
ll node(int n, int k) {
    return ((n-1)*K) + k;
}

void solve() {
    cin >> N >> K >> M;
    ll V = N * K + 2;
    ll S = V - 1;
    ll T = V - 2;
    
    max_flow pr(V);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        // connect all nodes of u to all nodes of v
        for (int j = 0; j < K; j++) {
            ll uu = node(u, j);
            ll vv = node(v, (j+1) % K);
            pr.add_edge(uu, vv, 1);
        }
    }
    // connect source to all producer nodes
    for (int i = 0; i < K; i++) {
        pr.add_edge(S, node(i+1, i), 1);
    }
    // connect final junction N to sink
    for (int i = 0; i < K; i++) {
        pr.add_edge(node(N, i), T, INF);
    }

    cout << pr.dinic(S, T) << endl;
    // debug(S, T);
    // pr.print();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}