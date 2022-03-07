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

int N, lo, hi;
bool isL, isR;

void query(int l1, int r1, int l2, int r2) {
    cout << "Q " + to_string(l1) + " " + to_string(r1) + " " + to_string(l2) + " " + to_string(r2) << endl;
}

void answer(int ans) {
    cout << "A " + to_string(ans) << endl;
    exit(0);
}

void read() {
    cin >> isL >> isR;
}

void solve() {
    cin >> N;
    lo = 1;
    hi = N;

    int l1, r1, l2, r2;
    while (hi - lo + 1 > 3) {
        l1 = lo;
        // r1 = lo + (int)(hi-lo+1)*0.5 - 1;
        r1 = lo + (int)(hi-lo+1)*0.5 - 1;
        l2 = lo + (int)(hi-lo+1)*0.25;
        // r2 = lo + (int)(hi-lo+1)*0.75 - 1;
        r2 = lo + (int)(hi-lo+1)*0.75;

        assert(l2 >= l1);
        assert(r1 >= l2);
        assert(r2 >= r1);

        query(l1, r1, l2, r2);
        read();
        
        if (isL and !isR) { // first part
            lo = max(1, l1-1);
            hi = l2;
            if (l2-l1 <= 1) answer(l1);
        } else if (isL and isR) {
            lo = l2-1;
            hi = r1+1;
            if (l2 == r1) answer(r1);
        } else if (!isL and isR) {
            lo = r1;
            hi = r2+1;
            if (r2-r1 <= 1) answer(r2);
        } else {
            lo = r2;
            hi = min(N, hi+1);
            if (hi-r2 == 1) answer(hi);
        }
    }

    // special case
    // if (hi - lo + 1 == 1) answer(lo);

    query(lo, lo, lo+1, lo+1);
    read();
    if (isL and !isR) answer(lo);
    else if (!isL and isR) answer(lo+1);
    else answer(hi);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}