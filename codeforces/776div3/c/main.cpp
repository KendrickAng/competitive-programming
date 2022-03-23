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
using iii = tuple<int,int,int>;

void solve() {
    int N, M; cin >> N >> M;
    priority_queue<iii, vector<iii>, greater<iii>> pts;
    for (int i = 0; i < M; i++) {
        int x, w; cin >> x >> w;
        pts.push({w, x, i+1});
    }

    vector<iii> chosen;
    ll sum = 0;
    for (int i = 0; i < 2*N; i++) {
        iii stuff = pts.top(); pts.pop();
        sum += get<0>(stuff);
        chosen.push_back(stuff);
    }

    sort(chosen.begin(), chosen.end(), [](iii &a, iii &b) {
        auto [aw, ax, ai] = a;
        auto [bw, bx, bi] = b;
        return ax < bx;
    });

    cout << sum << endl;
    for (int i = 0; i < N; i++) {
        auto [aw, ax, ai] = chosen[i];
        auto [bw, bx, bi] = chosen[2*N-i-1];
        cout << ai << " " << bi << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}