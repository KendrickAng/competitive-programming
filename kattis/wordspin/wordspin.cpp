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

int n;
string a, b;
vector<int> offset;
vector<int> dir;

ll update(int start, int end) {
    if (start == end) return 0;
    // find bottleneck
    // debug(start, end);
    int minOffset = *min_element(offset.begin()+start, offset.begin()+end);
    for (int i = start; i < end; i++) offset[i] -= minOffset;
    // continue updating remaining bits
    ll ret = minOffset;
    int i = start;
    while (i < end) {
        // now find the next subpart to update
        while (i < end and offset[i] == 0) i++;
        int nextStart = i;
        while (i < end and offset[i] > 0) i++;
        int nextEnd = i;
        ret += update(nextStart, nextEnd);
    }
    return ret;
}

void solve() {
    cin >> a >> b;
    n = a.size();
    offset.resize(n);
    dir.resize(n);

    for (int i = 0; i < n; i++) {
        char aa = a[i];
        char bb = b[i];
        if (aa == bb) {
            offset[i] = dir[i] = 0;
        } else {
            dir[i] = (aa < bb) ? -1 : 1;
            offset[i] = (aa < bb) ? bb-aa : aa-bb;
        }
    }

    int i = 0;
    ll ans = 0;
    while (i < n) {
        // go to next start point
        while (i < n and offset[i] == 0) i++;
        int start = i;
        int startDir = dir[i];
        // find next end point
        while (i < n and dir[i] == startDir) i++;
        int end = i;
        ans += update(start, end);
    }

    cout << ans << endl;
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}