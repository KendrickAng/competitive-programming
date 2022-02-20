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

vector<int> arr;
vector<int> p;
vector<int> lis;
vector<int> lisId;

void printLis(int i) {
    if (i == -1) return;
    printLis(p[i]);
    cout << arr[i] << ' ';
}

void solve(int n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    p.assign(n, -1);
    lisId.assign(n, 0);
    lis.assign(n, 0);
    int k = 0;
    int lisEnd = 0;
    
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis.begin(), lis.begin()+k, arr[i]) - lis.begin();
        lis[pos] = arr[i];
        lisId[pos] = i;
        // debug(lis);
        // debug(lisId);
        p[i] = pos ? lisId[pos-1] : -1;
        if (pos == k-1) lisEnd = i;
        else if (pos == k) {
            k = pos + 1;
            lisEnd = i;
        }
    }

    cout << k << ' ';
    printLis(lisEnd);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
}