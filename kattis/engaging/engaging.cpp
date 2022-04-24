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

/**
 * Description: Given array of (possibly negative) costs to complete 
 * each of $N$ (1-indexed) jobs w/ each of $M$ workers $(N\le M)$, 
 * finds min cost to complete all jobs such that each worker is 
 * assigned to at most one job. Dijkstra with potentials works
 * in almost the same way as MCMF.
 * Time: O(N^2M)
 */
ll HungarianMatch(const vector<vector<ll>>& costs, vector<ll> &matches) {
    ll n = costs.size()-1;
    ll m = costs[0].size()-1;
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
                    ll cur = costs[i0][j] - u[i0] - v[j];
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
    matches.assign(n+1, -1);
    for(ll j = 1; j <= m ; ++j)
        matches[p[j]] = j;

    return -v[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // gifts, customers, thank-you cards, by default, gifts on left group
    int nx, ny, numEdges; cin >> nx >> ny >> numEdges;

    // assume left group <= right group
    bool swapLeftRight = false;
    if (nx > ny) {
        swap(nx, ny);
        swapLeftRight = true;
    }

    vector<vector<ll>> costs;
    costs.assign(nx+1, vector<ll>(ny+1, 0));

    while (numEdges--) {
        // customer, gift, satisfaction
        int y, x, p; cin >> y >> x >> p;
        if (swapLeftRight) swap(x, y);
        costs[x][y] = -p;
    }

    vector<ll> matches;
    ll num = HungarianMatch(costs, matches);
    vector<ii> res;
    for (int i = 1; i < matches.size(); i++) {
        if (swapLeftRight) res.push_back({i, matches[i]});
        else res.push_back({matches[i], i});
    }

    cout << -1LL * num << endl;
    cout << res.size() << endl;
    for (auto it: res) cout << it.first << ' ' << it.second << endl;
}