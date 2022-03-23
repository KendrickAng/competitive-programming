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

struct pt {
    ll x;
    ll y;
};

int N, M;
vector<pt> bottles;
vector<pt> couriers;
vector<vector<ll>> cost;
pt rst;

ll HungarianMatch(const vector<vector<ll>>& a, vector<ll> &ans) {
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
    // vector<ll> ans(n+1);
    ans.assign(n+1, -1);
    for(ll j = 1; j <= m ; ++j) ans[p[j]] = j;

    return -v[0];
}

/**
 * Description: Given array of (possibly negative) costs to complete 
 * each of $N$ (1-indexed) jobs w/ each of $M$ workers $(N\le M)$, 
 * finds min cost to complete all jobs such that each worker is 
 * assigned to at most one job. Dijkstra with potentials works
 * in almost the same way as MCMF.
 * Time: O(N^2M)
 */
ll hungarian(const vector<vector<ll>> &a) {
    int N = a.size()-1;
    int M = a[0].size()-1;
    assert(N <= M);
    vector<ll> u(N+1);
    vector<ll> v(M+1);
    vector<int> job(M+1);
    debug(0);
    for (int i = 1; i <= N; i++) {
        const ll INF = numeric_limits<ll>::max();
        int w = 0; job[w] = i; // add dummy worker 0
        vector<ll> dist(M+1, INF);
        vector<int> pre(M+1, -1);
        vector<bool> done(M+1);
        while (job[w]) { // O(V^2) djikstra
            done[w] = 1;
            int j = job[w];
            int nexW;
            ll delta = INF;
            // fix dist[j], update distances from j
            for (int W = 0; W < M+1; W++) if (!done[W]) {
                if (a[j][W]-u[j]-v[W] < dist[W]) {
                    dist[W] = a[j][W]-u[j]-v[W];
                    pre[W] = w;
                }
                if (dist[W] < delta) {
                    delta = dist[W];
                    nexW = W;
                }
            }
            // subtract constant from all edges done -> not done vertices
            // effectively lowers all remaining dists by constant
            for (int W = 0; W < M+1; W++) {
                if (done[W]) {
                    u[job[W]] += delta;
                    v[W] -= delta;
                } else {
                    dist[W] -= delta;
                }
            }
            w = nexW;
        }
        for (int W; w; w = W) job[w] = job[W=pre[w]];
    }
    debug(u);
    debug(v);
    return -v[0]; // min cost
}

ll mhn(pt &a, pt &b) {
    return abs(b.x-a.x) + abs(b.y-a.y);
}

void solve() {
    cin >> N >> M;
    bottles.resize(N);
    couriers.resize(M);
    cost.assign(N+1, vector<ll>(N+M, 0));

    for (int i = 0; i < N; i++) cin >> bottles[i].x >> bottles[i].y;
    for (int i = 0; i < M; i++) cin >> couriers[i].x >> couriers[i].y;
    cin >> rst.x >> rst.y;

    // calculate bottle-courier costs
    for (int i = 0; i < N; i++) {
        // courier-bottle-restaurant
        for (int j = 0; j < M; j++) {
            cost[i+1][j+1] = mhn(couriers[j], bottles[i]) + mhn(bottles[i], rst);
        }
        // restaurant-bottle-restaurant
        for (int j = M; j < N+M-1; j++) {
            cost[i+1][j+1] = mhn(rst, bottles[i]) + mhn(bottles[i], rst);
        }
    }
    // debug(cost);

    vector<ll> left;
    cout << HungarianMatch(cost, left) << endl;
    debug(left);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}