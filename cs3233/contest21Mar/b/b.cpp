#pragma GCC optimize("O3")
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

#define LSOne(S) ((S) & -(S))
using ll = long long;
using ii = pair<int, int>;

int N, T;
vector<int> scores;
vector<int> memo;

int backtrack(int mask) {
    // base case
    if (mask == 0) return 0;

    int &ans = memo[mask];
    if (ans != -1) return ans;

    // haven't computed answer
    ans = 0;
    int two_pow_i = LSOne(mask);
    int i = __builtin_ctz(two_pow_i);
    // debug(mask, two_pow_i, i);
    for (int j = i+1; j < N; j++) {
        for (int k = j+1; k < N; k++) {
            int maskJ = 1 << j;
            int maskK = 1 << k;
            if ((mask & two_pow_i) && (mask & maskJ) && (mask & maskK) && (scores[i]+scores[j]+scores[k] >= T)) {
                // debug(i, j, k, scores[i]+scores[j]+scores[k], T);
                ans = max(ans, 1+backtrack(mask&(~two_pow_i)&(~maskJ)&(~maskK)));
                break;
            }
        }
    }
    if (ans == 0) ans = max(ans, backtrack(mask&(~two_pow_i)));

    return ans;
}

void solve() {
    scores.resize(N);
    memo.assign((1<<N), -1);

    // read input
    for (int i = 0; i < N; i++) cin >> scores[i];

    // sort by ascending scores
    // sort(scores.begin(), scores.end());
    // debug(scores);
    
    cout << backtrack((1<<N)-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        cin >> N >> T;
        if (N == 0 and T == 0) break;
        solve();
    }
}