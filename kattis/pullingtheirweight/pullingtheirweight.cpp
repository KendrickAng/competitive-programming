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

void solve() {
    int M; cin >> M;
    vector<ll> weights(M);
    vector<ll> prefix;
    vector<ll> freq(20010, 0);
    ll sum = 0;

    // read input
    for (int i = 0; i < M; i++) {
        ll tmp; cin >> tmp;
        weights[i] = tmp;
        freq[tmp]++;
        sum += tmp;
    }

    sort(weights.begin(), weights.end());
    unique(weights.begin(), weights.end());

    // form prefix sum array
    ll sofar = 0;
    for (ll weight: weights) {
        sofar += weight * freq[weight];
        prefix.push_back(sofar);
    }

    // find answer
    for (int i = 0; i < weights.size(); i++) {
        ll weight = weights[i];
        ll curr = freq[weight] * weight;
        if (prefix[i] == sum-prefix[i]) {
            cout << weight+1 << endl;
            return;
        }
        if (prefix[i]-curr == sum-prefix[i]) {
            cout << weight << endl;
            return;
        }
    }

    throw "uh oh";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}