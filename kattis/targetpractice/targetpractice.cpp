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

struct pt {
    ll x;
    ll y;
};

int N;
vector<pt> pts;

bool collinear(int a, int b, int c) {
    auto [x1, y1] = pts[a];
    auto [x2, y2] = pts[b];
    auto [x3, y3] = pts[c];
    // debug(x1, y1, x2, y2, x3, y3);
    ll tmp = x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3;
    return tmp == 0;
}

void solve() {
    cin >> N;
    pts.resize(N);

    if (N <= 4) {
        cout << "success" << endl;
        return;
    }

    // read input
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // find 3 collinear points - our first line
    int p1, p2, p3;
    bool isOk = false;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                if (collinear(i, j, k)) {
                    isOk = true;
                    p1 = i;
                    p2 = j;
                    p3 = k;
                }
            }
        }
    }

    if (!isOk) {
        cout << "failure" << endl;
        return;
    }

    // find the next line
    vector<int> others;
    for (int i = 0; i < N; i++) {
        if (i == p1 or i == p2 or i == p3) continue;
        if (!collinear(p1, p2, i)) others.push_back(i);
    }

    // verify the other line
    for (int i = 2; i < others.size(); i++) {
        if (!collinear(others[i-2], others[i-1], others[i])) {
            isOk = false;
            break;
        }
    }

    if (isOk) cout << "success" << endl;
    else cout << "failure" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}