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

ll N;
vector<int> as; // coefficients
vector<int> xs; // values of x
vector<vector<ll>> mat;
vector<ll> vec;

ll mod(ll a, ll m) {
    return ((a%m)+m)%m;
}

vector<ll> vecModMul(vector<vector<ll>> &mat, vector<ll> &vec, ll M) {
    vector<ll> ans(N+1, 0);
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            ans[i] += mod(mod(mat[i][j], M) * mod(vec[j], M), M);
        }
        ans[i] = mod(ans[i], M);
    }
    return ans;
}

vector<vector<ll>> matModMul(vector<vector<ll>> &a, vector<vector<ll>> &b, ll M) {
    vector<vector<ll>> ans(N+1, vector<ll>(N+1, 0));
    for (int i = 0; i < N+1; i++) {
        for (int k = 0; k < N+1; k++) {
            if (a[i][k] == 0) continue;
            for (int j = 0; j < N+1; j++) {
                ans[i][j] += mod(a[i][k], M) * mod(b[k][j], M);
                ans[i][j] = mod(ans[i][j], M);
            }
        }
    }
    return ans;
}

vector<vector<ll>> matModExp(vector<vector<ll>> base, ll p, ll M) {
    vector<vector<ll>> ans(N+1, vector<ll>(N+1, 0));
    for (int i = 0; i < N+1; i++) ans[i][i] = 1;
    while (p) { // p guaranteed at least 1
        // cout << p << endl;
        if (p&1) ans = matModMul(ans, base, M);
        base = matModMul(base, base, M);
        p >>= 1;
    }
    return ans;
}

ll query(ll T, ll M) {
    if (T < N) return xs[T] % M;
    vector<vector<ll>> m = matModExp(mat, T-N+1, M);
    vector<ll> v = vecModMul(m, vec, M);
    return v[1];
}

void solve() {
    cin >> N;
    as.resize(N+1);
    xs.resize(N);
    mat.assign(N+1, vector<ll>(N+1, 0));
    vec.resize(N+1);

    // read input
    for (int i = 0; i < N+1; i++) {
        cin >> as[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> xs[i];
    }

    // form matrix
    mat[0][0] = 1;
    for (int i = 0; i < N+1; i++) mat[1][i] = as[i];
    for (int i = 2; i < N+1; i++) mat[i][i-1] = 1;

    // form vector
    vec[0] = 1;
    for (int i = 1; i < vec.size(); i++) vec[i] = xs[xs.size()-i];

    // answer queries
    ll Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll T, M; cin >> T >> M;
        cout << query(T, M) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}