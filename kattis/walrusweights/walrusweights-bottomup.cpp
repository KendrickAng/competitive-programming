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
const int OFFSET = 1005;

int N;
int weights[MAX_N];
bool memo[MAX_N][MAX_W+OFFSET];

void setMemo(int n, int w, bool val) {
    memo[n][w+OFFSET] = val;
}

bool getMemo(int n, int w) {
    return memo[n][w+OFFSET];
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> weights[i];
    memset(memo, false, sizeof memo);

    // when filling the initial array, we want to handle negative offsets but negative indexes aren't allowed
    // so add a positive offset to all values; use helper functions since otherwise its error prone
    // base case
    setMemo(0, 1000, true);

    for (int i = 0; i < N; i++) {
        for (int j = MAX_W; j >= 0; j--) {
            if (getMemo(i, j)) {
                setMemo(i+1, j-weights[i], true); // took the weight
                setMemo(i+1, j, true); // didn't take the weight
            }
        }
    }

    // when finding the final answer, we want to retrieve the negative offsets, so ditch the helper functions
    int bestOffset = 1e9;
    for (int i = 0; i < MAX_W+OFFSET; i++) {
        if (memo[N][i]) {
            int offset = i - OFFSET; // retrieve the actual offset
            if (abs(offset) == abs(bestOffset)) {
                bestOffset = (offset < 0) ? offset : bestOffset; // take the negative offset
            } else if (abs(offset) < abs(bestOffset)) {
                bestOffset = offset; // better answer
            }
        }
    }
    cout << 1000 - bestOffset << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}