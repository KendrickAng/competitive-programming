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

int N, need;
vector<ll> integrity;
vector<ll> dailyDecay;
vector<ll> threshold;

bool isOk(ll days) {
    ll usableItems = 0;
    for (int i = 0; i < N; i++) {
        if (days <= threshold[i]) usableItems++;
    }
    return usableItems >= need;
}

ll ceiling(ll a, ll b) {
    return (a/b) + ((a%b) != 0);
}

void solve() {
    cin >> N >> need;
    integrity.resize(N);
    dailyDecay.resize(N);
    threshold.resize(N);

    // read input
    for (int i = 0; i < N; i++) cin >> integrity[i];
    for (int i = 0; i < N; i++) cin >> dailyDecay[i];

    // precalculate max days before item becomes unusable
    for (int i = 0; i < N; i++) {
        threshold[i] = ceiling(integrity[i], dailyDecay[i]) - 1;
    }

    // items needed exceeds items we have, definitely not solvable
    if (need > N) throw "uh oh";

    // brute force
    for (ll days = 5*1e18; days >= 0; days--) {
        if (isOk(days)) {
            cout << days << endl;
            return;
        }
    }

    // no answer
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}