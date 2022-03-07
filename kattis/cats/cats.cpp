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

int M, C;
vector<vector<ii>> adjList;
vector<bool> processed;
priority_queue<ii, vector<ii>, greater<ii>> pq; // min pq

void process(int node) {
    for (auto &[v, weight]: adjList[node]) {
        pq.push({weight, v});
    }
    processed[node] = true;
}

void solve() {
    cin >> M >> C;
    pq = priority_queue<ii, vector<ii>, greater<ii>>{};
    adjList.assign(C, vector<ii>());
    processed.assign(C, false);

    // read edges
    int E = C * (C-1) / 2;
    for (int i = 0; i < E; i++) {
        int u, v, dist; cin >> u >> v >> dist;
        adjList[u].push_back({v, dist});
        adjList[v].push_back({u, dist});
    }

    // mst
    ll spilled = 0;
    int S = 0;
    int numTaken = 0;
    process(S);
    while (!pq.empty()) {
        auto [weight, v] = pq.top(); pq.pop();
        if (processed[v]) continue;
        
        spilled += weight;
        process(v);

        numTaken++;
        if (numTaken == C-1) break; // optmisation
    }

    bool can = (spilled + C) <= M;
    cout << (can ? "yes" : "no") << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}