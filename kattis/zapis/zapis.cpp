#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

const int MOD = 100000;
vector<vector<ll>> memo;

int n;
string s;
bool exceeded = false;

vector<char> opens = {'(', '[', '{'};
vector<char> closes = {')', ']', '}'};

ll dp(int i, int j) {
    if (i > j) return 1; // the empty bracket sequence is valid

    ll &ans = memo[i][j];
    if (ans != -1) return ans;

    ll cnt = 0;
    for (int mid = i+1; mid <= j; mid += 2) {
        for (int typ = 0; typ < 3; typ++) {
            if ((s[i] == opens[typ] || s[i] == '?') && (s[mid] == closes[typ] || s[mid] == '?')) {
                cnt += dp(i+1, mid-1) * dp(mid+1, j);
            }
        }
    }

    if (cnt > MOD) {
        exceeded = true;
        cnt %= MOD;
    }

    return ans = cnt;
}

void solve() {
    cin >> n;

    // init memo table
    memo.assign(n, vector<ll>(n, -1));

    // read input string
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s.push_back(c);
    }

    ll ans = dp(0, n-1);

    if (exceeded) {
        cout << setfill('0') << setw(5);
    }
    cout << ans % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
