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

const int MAX_N = 101;
const int MAX_V = 101;
const int MOD = 1001113;

int memo[MAX_N][MAX_V];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // base cases
    for (int i = 0; i < MAX_N; i++) {
        memo[i][0] = 1;
        memo[0][i] = 1;
    }

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j < MAX_V; j++) {
            memo[i][j] = memo[i-1][j] * (j+1) + memo[i][j-1] * (i+1);
            memo[i][j] %= MOD;
        }
    }

    int t; cin >> t;
    while (t--) {
        int k, n, v; cin >> k >> n >> v;
        cout << k << " " << memo[n-v-1][v] << endl;
    }
}