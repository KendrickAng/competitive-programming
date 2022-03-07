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
    int N; cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];
    
    ll total = accumulate(nums.begin(), nums.end(), 0, plus<ll>());

    if (total % 3 != 0) {
        cout << -1 << endl;
    } else {
        ll marker = total / 3;
        ll sofar = 0;
        
        vector<int> markers;
        for (int i = 0; i < N; i++) {
            sofar += nums[i];
            if (sofar % marker == 0 and i != N-1) markers.push_back(i+1);
        }

        if (markers.size() != 2) {
            cout << -1 << endl;
        } else {
            for (ll m: markers) cout << m << ' ';
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}