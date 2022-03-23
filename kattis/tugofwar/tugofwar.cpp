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

const int MAX_N = 101;
const int MAX_W = MAX_N * 450 + 10;

int N;
vector<int> people;
vector<vector<bool>> possible;

void solve() {
    cin >> N;
    people.resize(N);
    possible.assign(MAX_N, vector<bool>(MAX_W, false));

    // read input
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> people[i];
        sum += people[i];
    }

    // dp variant
    possible[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = N/2; j >= 0; j--) {
            for (int w = 0; w <= 45000; w++) {
                if (possible[j][w]) possible[j+1][w+people[i]] = true;
            }
        }
    }

    // find a suitable split
    ll ans = 0;
    for (int w = 0; w <= 45000; w++) {
        if (possible[N/2][w] and (abs(sum - 2*w) < abs(sum - 2*ans))) {
            ans = w;
        }
    }

    if (sum-ans < ans) ans = sum-ans;
    cout << ans << " " << sum-ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}