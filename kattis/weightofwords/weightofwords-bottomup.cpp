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

const int MAX_L = 42;
const int MAX_W = 1002;

char memo[MAX_L][MAX_W];
vector<vector<ii>> pred;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int L, W; cin >> L >> W;
    if (L == 0) {
        cout << endl;
        return 0;
    }

    pred.assign(L+5, vector<ii>(W+5, {-1,-1}));

    memset(memo, 0, sizeof memo);
    for (char c = 'a'; c <= 'z'; c++) {
        memo[1][c-'a'+1] = c;
    }

    for (int i = 1; i < L; i++) {
        for (int j = 0; j <= W; j++) {
            if (memo[i][j]) {
                for (char c = 'a'; c <= 'z'; c++) {
                    // cout << i << ' ' << j << "->" << i+1 << ' ' << j+c << endl;
                    if (j+(c-'a'+1) > W) continue;
                    memo[i+1][j+(c-'a'+1)] = c;
                    pred[i+1][j+(c-'a'+1)] = {i,j};
                }
            }
        }
    }

    if (memo[L][W]) {
        ii pos = {L,W};
        while (true) {
            cout << memo[pos.first][pos.second];
            pos = pred[pos.first][pos.second];
            if (pos.first == -1 and pos.second == -1) break;
        }
        cout << endl;
    } else {
        cout << "impossible" << endl;
    }
}