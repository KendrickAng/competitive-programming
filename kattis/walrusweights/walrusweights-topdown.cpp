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

const int MAX_N = 1005;
const int MAX_W = 1005;

int N;
int weights[MAX_N];
int memo[MAX_N][MAX_W];

int dp(int pos, int weight) {
    if (pos >= N or weight < 0) return -1 * weight;
    int &ans = memo[pos][weight];
    if (ans == -1) {
        int a = dp(pos+1, weight-weights[pos]); // take
        int b = dp(pos+1, weight); // don't take
        if (abs(a) == abs(b)) {
            if (a > b) ans = a;
            else ans = b;
        } else if (abs(a) < abs(b)) {
            ans = a;
        } else {
            ans = b;
        }
    }
    return ans;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> weights[i];
    memset(memo, -1, sizeof memo);
    cout << 1000 + dp(0, 1000) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}