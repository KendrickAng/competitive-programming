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

int N, W;
vector<vector<int>> ticPrice;
vector<vector<int>> ticAmt;
vector<int> bestIdx;
const int MAX_W = 53;
const int MAX_N = 301;
int memo[MAX_N][MAX_W];

int dp(int tickets, int week) {
    if (week > W or tickets <= 0) return 0;
    int &ans = memo[tickets][week];
    if (ans == -1) {
        int tmp = -1;
        int k = ticPrice[week].size();
        for (int tIdx = 0; tIdx < k; tIdx++) {
            int tixLeft = ticAmt[week][tIdx];
            int tixPrice = ticPrice[week][tIdx];
            int tixSold = min(tixLeft, tickets);
            int earned = (tixSold*tixPrice) + dp(tickets-tixSold, week+1);
            if (earned > tmp) {
                tmp = earned;
                bestIdx[week] = tIdx;
            }
        }
        ans = tmp;
    }
    return ans;
}

void solve() {
    ticPrice.assign(W+1, vector<int>());
    ticAmt.assign(W+1, vector<int>());
    bestIdx.assign(W+1, -1);
    for (int i = 0; i <= W; i++) {
        int K; cin >> K;
        ticPrice[i].assign(K, 0);
        ticAmt[i].assign(K, 0);
        for (int j = 0; j < K; j++) cin >> ticPrice[i][j];
        for (int j = 0; j < K; j++) cin >> ticAmt[i][j];
    }
    memset(memo, -1, sizeof memo);
    int ans = dp(N, 0);
    cout << ans << endl;
    cout << ticPrice[0][bestIdx[0]] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> W;
    solve();
}