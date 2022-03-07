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
const int MAX_M = 41;
const int MAX_DIST = 1001;
int memo[MAX_M][MAX_DIST];
int dir[MAX_M][MAX_DIST];

void solve() {
    cin >> M;
    
    // read input
    climb.resize(M);
    for (int i = 0; i < M; i++) cin >> climb[i];

    // dp
    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < MAX_DIST; j++) {
            memo[i][j] = -1;
        }
    }
    
    // base cases
    memo[M][0] = 0;
    for (int i = M-1; i >= 0; i--) {
        for (int j = 0; j < MAX_DIST; j++) {
            int climbed = climb[i];
            // always prefer climbing up
            if (j + climbed < MAX_DIST and memo[i+1][j+climbed] != -1) {
                memo[i][j] = max(j, memo[i+1][j+climbed]);
                dir[i][j] = 1;
            }
            // only update climbing down if we have a worse solution (clmbing down from higher height)
            if (j - climbed >= 0 and memo[i+1][j-climbed] != -1 and (memo[i][j] == -1 or memo[i][j] > memo[i+1][j-climbed])) {
                memo[i][j] = max(j, memo[i+1][j-climbed]);
                dir[i][j] = -1;
            }
        }
    }

    // find ans
    if (memo[0][0] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int curr = 0;
        for (int i = 0; i < M; i++) {
            char direction = dir[i][curr] == 1 ? 'U' : 'D';
            cout << direction;
            curr += dir[i][curr] * climb[i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}