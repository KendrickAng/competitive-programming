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
vector<int> subsets;

int backtrack(int mask) {
    // base case
    if (mask == 0) return 0;

    int &ans = memo[mask];
    if (ans != -1) return ans;

    // haven't computed answer
    ans = 0;
    int maxTeams = __builtin_popcount(mask) / 3;
    for (int subsetMask: subsets) {
        if ((mask & subsetMask) == subsetMask) {
            ans = max(ans, 1 + backtrack(mask & (~subsetMask)));
            if (ans == maxTeams) break; // found the max number of teams
        }
    }

    return ans;
}

void solve() {
    scores.resize(N);
    subsets.clear();
    memo.assign((1<<N), -1);

    // read input
    for (int i = 0; i < N; i++) cin >> scores[i];

    // form all possible subsets of students
    for (int mask = 0; mask < (1<<N); mask++) {
        // take all masks with 3 on bits
        if (!(__builtin_popcount(mask) == 3)) continue; 

        int sum = 0;
        for (int i = 0; i < N; i++) {
            if ((1 << i) & mask) sum += scores[i];
        }
        if (sum >= T) subsets.push_back(mask);
    }
    
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