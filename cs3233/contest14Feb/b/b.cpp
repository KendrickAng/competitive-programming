#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

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

int N, V, E;
const int MAX_V = 55;
const ll INF = 1e17;

struct Matrix {
    ll mat[MAX_V][MAX_V];
};

Matrix adjMat;

void print(Matrix m) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << m.mat[i][j] << ' ';
        }
        cout << endl;
    }
}

Matrix matMul(Matrix a, Matrix b) {
    // debug("MULTIPLYING)");
    // print(a);
    // print(b);
    Matrix ans;
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            ans.mat[i][j] = -INF;
    for (int i = 0; i < V; ++i) {
        for (int k = 0; k < V; ++k) {
            //   if (a.mat[i][k] == 0) continue;            // optimization
            for (int j = 0; j < V; ++j) {
                ll next = a.mat[i][k] + b.mat[k][j];
                if (a.mat[i][k] == -INF || b.mat[k][j] == -INF) next = -INF;
                ans.mat[i][j] = max(ans.mat[i][j], next);
            }
        }
    }
    // print(ans);
    return ans;
}

Matrix matPow(Matrix base, int p) {
    // debug(p);
    Matrix ans;                                    // but O(log p) as n = 2
    for (int i = 0; i < MAX_V; ++i)
        for (int j = 0; j < MAX_V; ++j)
            ans.mat[i][j] = adjMat.mat[i][j];
    while (p) {                                    // iterative D&C version
        if (p&1)                                     // check if p is odd
            ans = matMul(ans, base);
        base = matMul(base, base);                   // square the base
        p >>= 1;                                     // divide p by 2
    }
    return ans;
}

void solve() {
    cin >> N >> V >> E;
    // debug(N, V, E);

    // read input
    for (int i = 0; i < MAX_V; i++) {
        for (int j = 0; j < MAX_V; j++) {
            adjMat.mat[i][j] = -INF;
        }
    }
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adjMat.mat[u][v] = w;
    }
    
    // no self-loops
    for (int i = 0; i < V; i++) {
        adjMat.mat[i][i] = -INF;
    }

    // modified matrix power
    Matrix final = matPow(adjMat, N-2);

    // print(final);

    // find answer?
    ll ans = -INF;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            ans = max(ans, final.mat[i][j]);
        }
    }

    if (ans <= -INF) {
        cout << "Sad bunny :(" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}