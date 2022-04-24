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

int N;
vector<string> arr;

void solve() {
    cin >> N;
    arr.reserve(N);
    
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        reverse(tmp.begin(), tmp.end());
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < arr.size()-1; i++) {
        string s1 = arr[i];
        string s2 = arr[i+1];
        if (s1.size() > s2.size()) swap(s1, s2);
        if (s2.find(s1) == 0) continue;

        int eq = 0;
        int len = min(s1.size(), s2.size());
        for (int j = 0; j < len; j++) {
            if (s1[j] == s2[j]) eq++;
            else break;
        }
        ans = max(ans, eq);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}