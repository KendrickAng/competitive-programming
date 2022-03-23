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
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;
typedef vector<ll> vll;
struct edge {
    int u, v;
    ll w;
    edge (int uu = 0, int vv = 0, ll ww = 0) : u(uu), v(vv), w(ww) {}
    bool operator<(const edge& rhs) const {
        return w > rhs.w;
    }
};
typedef vector<vector<edge>> vve;
const int INF = 1e9;

int N, M, C;
vector<vector<pair<ll,ll>>> adjList;
vector<int> pred;
vector<int> cli;

// mcbm
// vector<vector<int>> AL;
// vector<int> match;
// vector<bool> vis;

// int Aug(int left) {
//     if (vis[left]) return 0;
//     vis[left] = 1;
//     for (int right: AL[left]) {
//         if ((match[right] == -1 || Aug(match[right]))) {
//             match[right] = left;
//             return 1;
//         }
//     }
//     return 0;
// }

void djikstra(int start, vector<ll> &dist) {
    dist.assign(N, INF);
    dist[start] = 0;
    set<ii> pq;
    for (int i = 0; i < N; i++) {
        pq.insert({ dist[i], i });
    }
    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [v, w]: adjList[u]) {
            if (dist[u] + w < dist[v]) {
                pq.erase(pq.find({ dist[v], v }));
                dist[v] = dist[u] + w;
                pred[v] = u;
                pq.insert({ dist[v], v });
            }
        }
    }
}

bool dfs(int i, vi& m, const vvi& bip, vi& seen) {
    if (seen[i]) return false;
    seen[i] = 1;

    for (auto j : bip[i])
        if (m[j+bip.size()] == -1 || dfs(m[j+bip.size()], m, bip, seen)) {
            m[j+bip.size()] = i; m[i] = j+bip.size();
            return true;
        }

    return false;
}

bool augment(const vvi& bip, vi& m) {
    vi seen(bip.size(), false);

    for (int i = 0; i < bip.size(); ++i)
        if (m[i] == -1 && dfs(i, m, bip, seen)) return true;
    return false;
}

int match1(const vvi& bip) {
    int cnt = 0;
    vi m(2*bip.size(), -1);
    while (augment(bip, m)) ++cnt;

    //for (auto x : m) cout << x << ' '; cout << endl;

    return cnt;
}

void dijkstra2(int s, const vve& g, vll& d) {
    priority_queue<edge> pq;
    d.assign(g.size(), -1);
    pq.push(edge(-1, s, 0));

    while (!pq.empty()) {
        edge curr = pq.top();
        pq.pop();

        if (d[curr.v] != -1) continue;
        d[curr.v] = curr.w;

        for (auto nxt : g[curr.v]) {
            nxt.w += curr.w;
            pq.push(nxt);
        }
    }
}

void solve() {
    cin >> N >> M >> C;
    adjList.assign(N, vector<pair<ll,ll>>());
    cli.resize(C);

    // read input
    for (int i = 0; i < C; i++) {
        cin >> cli[i];
    }
    vve g(N);
    while (M--) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        g[e.u].push_back(e);
    }

    // find shortest path spanning tree
    vector<ll> d0;
    dijkstra2(0, g, d0);
    debug(d0);
    vector<vector<int>> bip(C);
    for (int i = 0; i < C; i++) {
        vector<ll> d;
        dijkstra2(cli[i], g, d);
        debug(d);
        for (int j = 0; j < C; j++) {
            if (i != j and d[cli[j]] != INF and (d0[cli[i]] + d[cli[j]] == d0[cli[j]])) {
                bip[i].push_back(j);
            }
        }
    }
    // debug(bip);

    // int VLeft = bip.size();
    // int V = VLeft + rhs.size();
    // AL.assign(V, vector<int>());

    // int id = VLeft;
    // vector<int> rhsMap(N, -1);
    // for (int right: rhs) {
    //     if (rhsMap[right] == -1) rhsMap[right] = id++;
    // }

    // for (int u = 0; u < VLeft; u++) {
    //     for (int right: bip[u]) {
    //         AL[u].push_back(rhsMap[right]);
    //     }
    // }

    // match.assign(V, -1);
    // int MCBM = 0;
    // for (int i = 0; i < VLeft; i++) {
    //     vis.assign(VLeft, false);
    //     MCBM += Aug(i);
    // }

    cout << C - match1(bip) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}