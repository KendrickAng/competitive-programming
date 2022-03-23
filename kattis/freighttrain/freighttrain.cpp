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

int N, W, L;
vector<int> freights;

bool isOk(int wagons) { // max length of a wagon
    int left = 0;
    int right = wagons-1;
    int i = 0;
    int count = 0;
    while (left <= right) {
        count++;
        if (i == W) break;
        if (freights[i] > right) {
            left = freights[i];
        } else {
            while(++i < W and freights[i] <= right) {
                // do nothing
            }
            left = right + 1;
        }
        right = min(left+wagons-1, N-1);
    }
    return count <= L;
}

void solve() {
    cin >> N >> W >> L;
    freights.assign(W, false);

    // read input
    for (int i = 0; i < W; i++) {
        cin >> freights[i];
        freights[i]--;
    }

    // bsta
    int lo = 1;
    int hi = N;
    int last = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // debug(lo, hi, mid);
        if (isOk(mid)) {
            hi = mid - 1;
            last = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << last << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}