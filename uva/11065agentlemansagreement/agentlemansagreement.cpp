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

#define LSOne(S) ((S) & -(S))
using ll = long long;
using ii = pair<int, int>;

const int MAX_V = 62;

vector<ll> adjMat(62, 0);
int N, V, E;
int numIS;
int MIS;

void backtrack(int u, ll mask, int depth) {
    if (mask == 0) {
        numIS++;
        MIS = max(MIS, depth);
        return;
    }
    ll m = mask;
    while (m) {
        ll two_pow_v = LSOne(m);
        int v = __builtin_ctzll(two_pow_v);
        m -= two_pow_v;
        if (v < u) continue; // prevent double counting
        backtrack(v+1, mask & ~adjMat[v], depth+1); // seal off neighbours of v
    }
}

void solve() {
    cin >> N;
    while (N--) {
        cin >> V >> E;
        // initialize adjMat
        for (int u = 0; u < V; u++) {
            adjMat[u] = (1LL << u);
        }
        // read edges
        for (int i = 0; i < E; i++) {
            int u, v; cin >> u >> v;
            adjMat[u] |= (1LL << v);
            adjMat[v] |= (1LL << u);
        }
        numIS = 0;
        MIS = 0;
        backtrack(0, (1LL << V) - 1, 0);
        cout << numIS << endl;
        cout << MIS << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}