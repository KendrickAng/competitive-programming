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
using iii = tuple<int,int,int>;

int T, R, C;
vector<vector<char>> grid;
vector<vector<bool>> seen;

bool valid(int r, int c) {
    return r >= 0 and r < R and c >= 0 and c < C;
}

bool validUp(int r, int c) {
    return valid(r, c) and (grid[r][c] == '0' or grid[r][c] == 'D');
}

bool validDown(int r, int c) {
    return valid(r, c) and (grid[r][c] == '0' or grid[r][c] == 'U');
}

bool validLeft(int r, int c) {
    return valid(r, c) and (grid[r][c] == '0' or grid[r][c] == 'R');
}

bool validRight(int r, int c) {
    return valid(r, c) and (grid[r][c] == '0' or grid[r][c] == 'L');
}

void solve() {
    cin >> T >> R >> C;
    seen.assign(R, vector<bool>(C, false));
    grid.assign(R, vector<char>(C));

    int sr, sc;

    // read input
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }

    // bfs
    queue<iii> q;
    q.push({sr, sc, 0});
    while (!q.empty()) {
        auto [r, c, time] = q.front(); q.pop();
        if (time <= T and (r == 0 or r == R-1 or c == 0 or c == C-1)) {
            cout << time << endl;
            return;
        }

        // check up
        if (validUp(r-1, c) and !seen[r-1][c]) {
            seen[r-1][c] = true;
            q.push({r-1, c, time+1});
        }
        if (validDown(r+1, c) and !seen[r+1][c]) {
            seen[r+1][c] = true;
            q.push({r+1, c, time+1});
        }
        if (validLeft(r, c-1) and !seen[r][c-1]) {
            seen[r][c-1] = true;
            q.push({r, c-1, time+1});
        }
        if (validRight(r, c+1) and !seen[r][c+1]) {
            seen[r][c+1] = true;
            q.push({r, c+1, time+1});
        }
    }

    cout << "NOT POSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}