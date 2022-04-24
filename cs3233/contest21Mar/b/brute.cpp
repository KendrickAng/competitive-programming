#pragma GCC optimize("O3")
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

int N, T;
vector<int> scores;
vector<ll> memo;

ll backtrack(ll mask) {
    // base case
    if (mask == 0) return 0;

    ll &ans = memo[mask];
    if (ans != -1) return ans;

    // haven't computed answer
    ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                ll maskI = 1LL<<i;
                ll maskJ = 1LL<<j;
                ll maskK = 1LL<<k;
                if ((mask & maskI) && (mask & maskJ) && (mask & maskK)) {
                    ll powerLvl = scores[i] + scores[j] + scores[k];
                    if (powerLvl < T) continue;
                    // debug(i, j, k, powerLvl, T);
                    ans = max(ans, 1+backtrack(mask&(~maskI)&(~maskJ)&(~maskK)));
                }
            }
        }
    }

    return ans;
}

void solve() {
    scores.resize(N);
    memo.assign((1LL<<N), -1);

    // read input
    for (int i = 0; i < N; i++) cin >> scores[i];

    ll ans = backtrack((1LL<<N)-1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        cin >> N >> T;
        if (N == 0 and T == 0) break;
        solve();
    }
}