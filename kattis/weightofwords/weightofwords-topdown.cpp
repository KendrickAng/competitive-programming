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
using cii = tuple<char, int, int>;

const int MAX_L = 45;
const int MAX_W = 1005;

int memo[MAX_L][MAX_W];
cii pred[MAX_L][MAX_W];

void print(int l, int w, string &s) {
    if (l == -1 and w == -1) return;
    auto [c, l2, w2] = pred[l][w];
    if (c != '\0') s += c;
    print(l2, w2, s);
}

int dp(int len, int weight) {
    if (len == 0 and weight == 0) return 1;
    if (len <= 0) return 0;
    if (weight <= 0) return 0;
    int &ans = memo[len][weight];
    if (ans == -1) {
        bool tmp = false;
        for (char c = 'a'; c <= 'z'; c++) {
            int can = dp(len-1, weight-(c-'a'+1));
            if (can == 1) {
                tmp = true;
                pred[len][weight] = {c,len-1,weight-(c-'a'+1)};
            }
        }
        ans = tmp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int L, W; cin >> L >> W;

    // initialize data structures
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < MAX_L; i++) {
        for (int j = 0; j < MAX_W; j++) {
            pred[i][j] = {'\0', -1, -1};
        }
    }

    if (dp(L, W) == 1) {
        string s;
        print(L, W, s);
        cout << s << endl;
    } else {
        cout << "impossible" << endl;
    }
}