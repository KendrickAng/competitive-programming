#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

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

int rsq(vector<int> &cum, int i, int j) {
    return cum[j+1] - cum[i];
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // debug(arr);

    vector<int> cum;
    cum.push_back(0);
    for (int i = 0; i < n; i++) {
        cum.push_back(cum.back() + arr[i]);
    }
    // debug(cum);

    int ans = -1;
    int sum = 0;

    int mcount = 0;
    int mprev = -1;
    int minprev = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (arr[i] < m) {
            if (mcount == 1) ans = max(ans, sum-arr[i]);
            sum = 0;
            mcount = 0;
            minprev = i;
        } else if (arr[i] == m) {            
            mcount++;
            if (mcount == 2) {
                ans = max(ans, sum-m);
                int previdx = max(minprev+1, mprev+1);
                // debug(previdx, i);
                sum = rsq(cum, previdx, i);
                mcount = 1;
            }
            mprev = i;
            if (mcount == 1) ans = max(ans, sum);
        } else {
            if (mcount == 1) ans = max(ans, sum);
        }
        // debug(i, sum, ans);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}