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

int M;
vector<int> climb;
const int INF = 1e9;
const int MAX_M = 45;
const int MAX_DIST = 1010;
int memo[MAX_M][MAX_DIST];

int dp(int idx, int height) {
    if (idx == 0 and height == 0) return 0;
    if (height < 0) return -INF;

    int &ans = memo[idx][height];
    if (ans != -1) return ans;

    ans = INF;
    ans = min(ans, dp(idx-1, height-climb[idx]) + height);
    ans = min(ans, dp(idx-1, height+climb[idx]) - height);

    return ans;
}

void printDP(int i, int h) {
    if (i == 0) return;
    if (dp(i-1, h-climb[i])) {
        printDP(i-1, h-climb[i]);
        cout << 'U';
    } else {
        printDP(i-1, h+climb[i]);
        cout << 'D';
    }
}

void solve() {
    cin >> M;
    
    // read input
    climb.resize(M);
    for (int i = 0; i < M; i++) cin >> climb[i];

    // dp
    memset(memo, -1, sizeof memo);
    int ans = dp(M, 0);
    debug(ans);
    if (ans == -INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // printDP(M, 0);
        cout << "OK" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}