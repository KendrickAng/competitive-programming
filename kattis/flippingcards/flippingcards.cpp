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

vector<vector<int>> AL;
vector<int> match;
vector<bool> vis;

int Aug(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    for (int v: AL[u]) {
        if ((match[v] == -1) or Aug(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    AL.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        AL[i].push_back(u+n);
        AL[i].push_back(v+n);
    }

    int MCBM = 0;
    match.assign(3*n, -1);
    for (int u = 0; u < n; u++) {
        vis.assign(3*n, false);
        MCBM += Aug(u);
    }

    cout << (MCBM == n ? "possible" : "impossible") << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}