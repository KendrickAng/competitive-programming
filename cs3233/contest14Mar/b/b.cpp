#pragma GCC optimize("O2")
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

/**
 * Description: Given array of (possibly negative) costs to complete 
 * each of $N$ (1-indexed) jobs w/ each of $M$ workers $(N\le M)$, 
 * finds min cost to complete all jobs such that each worker is 
 * assigned to at most one job. Dijkstra with potentials works
 * in almost the same way as MCMF.
 * Time: O(N^2M)
 */
ll HungarianMatch(const vector<vector<ll>>& a, vector<ll> &lhs) {
    ll n = a.size()-1;
    ll m = a[0].size()-1;
    vector<ll> u(n+1), v(m+1), p(m+1), way(m+1);
    const ll inf = numeric_limits<ll>::max();
    for(ll i = 1; i <= n; ++i) {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(m+1, inf);
        vector<char> used(m+1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = inf, j1;
            for(ll j = 1; j <= m; ++j)
                if(!used[j]) {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for(ll j = 0; j <= m; ++j)
                if(used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while(p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }

    // For each N, it contains the M it selected
    lhs.resize(n+1);
    for(ll j = 1; j <= m ; ++j) lhs[p[j]] = j;

    return -v[0];
}

using ii = pair<int, int>;

int N;
vector<vector<ll>> costs;

void solve(int T) {
    cin >> N;
    costs.assign(N+1, vector<ll>(N+1, 1e18));

    // read input
    for (int u = 0; u < N; u++) {
        int V; cin >> V;
        for (int j = 0; j < V; j++) {
            int v; cin >> v;
            costs[u+1][v+1] = 1;
        }
    }

    // first run of hungarian
    vector<ll> rhs;
    ll mcbm1 = HungarianMatch(costs, rhs);
    if (mcbm1 != N) {
        cout << "Case " << T << ": " << "no" << endl;
        return;
    }

    // update edge costs
    for (int u = 1; u <= N; u++) {
        costs[u][rhs[u]] *= 2;
    }

    // second run of hungarian
    ll mcbm2 = HungarianMatch(costs, rhs);
    if (mcbm2 != 2*N) {
        cout << "Case " << T << ": " << "no" << endl;
        return;
    }

    cout << "Case " << T << ": " << "yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    int tt = 1;
    while (t--) solve(tt++);
}