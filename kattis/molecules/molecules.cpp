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

struct point {
    double x;
    double y;
};

int N, M;
vector<point> pts;
vector<point> tmp;
vector<bool> isFixed;
vector<vector<int>> adjList;

void solve() {
    cin >> N >> M;
    pts.resize(N);
    tmp.resize(N);
    isFixed.assign(N, false);
    adjList.assign(N, vector<int>());

    // read points
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {(double) x, (double) y};
        isFixed[i] = !(x == -1 and y == -1);
    }

    // read bonds
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < 1e5; i++) {
        for (int u = 0; u < N; u++) {
            if (isFixed[u]) {
                tmp[u] = pts[u];
            } else {
                // get average positions of all points
                point avg{0.0, 0.0};
                for (int v: adjList[u]) {
                    avg.x += pts[v].x;
                    avg.y += pts[v].y;
                }
                int n = adjList[u].size();
                tmp[u] = {avg.x/n, avg.y/n};
            }
        }
        pts = vector<point>(tmp.begin(), tmp.end());
    }

    cout << fixed << setprecision(10) << endl;
    for (const point &p: pts) {
        cout << p.x << " " << p.y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}