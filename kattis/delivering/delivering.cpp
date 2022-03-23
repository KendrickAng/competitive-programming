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

const ll INF = 1e18;;

int N, M, C;
vector<vector<pair<ll, ll>>> adjList;
vector<int> cli;

// mcbm
vector<vector<int>> AL;
vector<int> match;
vector<bool> vis;

int Aug(int left, vector<vector<int>> &g) {
    if (vis[left]) return 0;
    vis[left] = 1;
    for (int right: g[left]) {
        if ((match[right] == -1 || Aug(match[right], g))) {
            match[right] = left;
            return 1;
        }
    }
    return 0;
}

void djikstra(int start, vector<ll> &dist) {
    dist.assign(N, INF);
    set<ii> pq;
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        pq.insert({ dist[i], i });
    }
    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [v, w]: adjList[u]) {
            if (dist[u] + w < dist[v]) {
                pq.erase({ dist[v], v });
                dist[v] = dist[u] + w;
                pq.insert({ dist[v], v });
            }
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
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({ v, w });
    }

    // find shortest path spanning tree
    vector<ll> d0;
    djikstra(0, d0);
    debug(d0);
    vector<vector<int>> bip(C);
    unordered_set<int> rhs;
    for (int i = 0; i < C; i++) {
        vector<ll> d;
        djikstra(cli[i], d);
        for (int j = 0; j < C; j++) {
            if (i != j and d[cli[j]] != INF and (d0[cli[i]] + d[cli[j]] == d0[cli[j]])) {
                // debug(cli[i], cli[j]);
                bip[i].push_back(j);
                rhs.insert(j);
            }
        }
    }
    for (int u = 0; u < bip.size(); u++) {
        if (bip[u].empty()) continue;
        cout << cli[u] << ": ";
        for (int j: bip[u]) {
            cout << cli[j] << " ";
        }
        cout << endl;
    }

    int VLeft = bip.size();
    int V = VLeft + rhs.size();
    match.assign(V, -1);
    int MCBM = 0;
    for (int i = 0; i < VLeft; i++) {
        vis.assign(VLeft, false);
        MCBM += Aug(i, bip);
    }

    cout << C - MCBM << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
