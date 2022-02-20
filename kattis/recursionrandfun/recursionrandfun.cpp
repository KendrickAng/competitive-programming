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

const int MAX_A = 10;
const int MAX_B = 10;
const int MAX_C = 10;
const int MAX_I = 105;
const int MAX_K = 10005;
int memo[MAX_I][MAX_K]; 

int dp(int ii, int kk, int a, int b, int c) {
    if (ii <= 0) return kk == 1;
    int &ans = memo[ii][kk];
    if (ans != -1) return ans;

    bool can = false;
    for (int bb = 0; bb < b; bb++) {
        for (int cc = 0; cc < c; cc++) {
            can = can || dp(ii-1-cc, kk-a-bb, a, b, c);
        }
    }

    return ans = can;
}

void solve(int a, int b, int c, int i, int k) {
    int can = dp(i, k, a, b, c);
    // debug(can);
    if (can == 1) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, i, k;
    while (cin >> a >> b >> c >> i >> k) {
        memset(memo, -1, sizeof memo);
        solve(a, b, c, i, k);
    }
}