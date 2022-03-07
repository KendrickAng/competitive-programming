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
using iii = tuple<int, int, int>;
using iiiii = tuple<int, int, int, int, int>;

struct hasher {
    size_t operator()(const ii &pr) const {
        return ((ll) pr.first + 1e6) * 1e9 + (pr.second + 1e6);
    }
};

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> processed;
priority_queue<iiiii, vector<iiiii>, greater<iiiii>> pq;
unordered_map<ii, vector<iii>, hasher> adjList;

vector<int> rOff = {-1, 1, 0, 0};
vector<int> cOff = {0, 0, 1, -1};

bool valid(int r, int c) {
    return r >= 0 and r < R and c >= 0 and c < C;
}

void process(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int newR = r + rOff[i];
        int newC = c + cOff[i];
        if (valid(newR, newC)) {
            int cost = grid[newR][newC] - grid[r][c];
            if (cost < 0) cost = 0;
            pq.push({cost, newR, newC, r, c});
        }
    }
    processed[r][c] = true;
}

void solve() {
    cin >> R >> C;
    int V = R * C;
    grid.assign(R, vector<int>(C));
    processed.assign(R, vector<bool>(C, false));
    adjList.clear();
    pq = priority_queue<iiiii, vector<iiiii>, greater<iiiii>>{};

    // read input
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int sr = 0;
    int sc = 0;
    int tr = R-1;
    int tc = C-1;
    int numProcessed = 0;
    process(sr, sc);
    vector<ii> mst;
    while (!pq.empty()) {
        auto [weight, r, c, prevR, prevC] = pq.top(); pq.pop();
        if (processed[r][c]) continue;
        // debug(r, c, weight);
        process(r, c);

        adjList[{prevR, prevC}].push_back({r, c, weight});

        numProcessed++;
        if (numProcessed == V-1) break;
    }

    // bfs
    queue<iii> q;
    q.push({0, 0, 0});
    processed.assign(R, vector<bool>(C, false)); // reuse
    processed[0][0] = true;
    while (!q.empty()) {
        auto [r, c, maxW] = q.front(); q.pop();
        if (r == tr and c == tc) {
            cout << maxW << endl;
            return;
        }

        for (auto [rr, cc, weight]: adjList[{r,c}]) {
            if (processed[rr][cc]) continue;

            processed[rr][cc] = true;
            q.push({rr, cc, max(maxW, weight)});
        }
    }

    throw "what the";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}