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

#define LSOne(i) (i&(-i))
using ll = long long;
using ii = pair<int, int>;

int N, S;
vector<ll> blockH;
vector<ll> buildH;
unordered_map<ll, vector<ll>> sumToSubset;
vector<ll> used;
vector<vector<int>> memo;

bool backtrack(int buildingIdx, int left) {
    if (memo[buildingIdx][left]) return false;

    // tried all buildings, found a solution (left doesn't need to be 0)
    if (buildingIdx == S) {
        return true;
    }
    ll buildingHeight = buildH[buildingIdx];
    for (ll mask: sumToSubset[buildingHeight]) {
        // all building we need must be present
        if ((left & mask) != mask) continue;
        // otherwise, try this solution
        used.push_back(mask);
        if (backtrack(buildingIdx+1, left & (~mask))) {
            return true;
        }
        used.pop_back();
    }

    memo[buildingIdx][left] = true; // remember that this combi doesn't work
    return false;
}

void solve() {
    cin >> N >> S;
    blockH.resize(N);
    buildH.resize(S);
    memo.assign(N+1, vector<int>((1 << N), false));

    // read input
    for (int i = 0; i < N; i++) cin >> blockH[i];
    for (int i = 0; i < S; i++) cin >> buildH[i];

    // form all possible subsets of blocks (with their sums)
    for (int mask = 0; mask < (1 << N); mask++) {
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            if ((1 << i) & mask) {
                sum += blockH[i];
            }
        }
        sumToSubset[sum].push_back(mask);
    }

    if (backtrack(0, (1 << N) - 1)) {
        for (int i = 0; i < used.size(); i++) {
            ll mask = used[i];
            ll len = __builtin_popcount(mask);
            cout << len << " ";
            while (mask) {
                int twoPowV = LSOne(mask);
                int v = __builtin_ctz(twoPowV);
                cout << v+1 << " ";
                mask -= twoPowV;
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}