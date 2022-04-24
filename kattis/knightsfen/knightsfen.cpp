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

const int INF = 1e9;
vector<vector<char>> grid;

const vector<int> rOff = {-1,1,2,2,1,-1,-2,-2};
const vector<int> cOff = {-2,-2,-1,1,2,2,1,-1};
const vector<vector<char>> correct = {
    {'1','1','1','1','1'},
    {'0','1','1','1','1'},
    {'0','0',' ','1','1'},
    {'0','0','0','0','1'},
    {'0','0','0','0','0'}
};

bool isFinal() {
    return grid == correct;
}

bool isValid(int r, int c) {
    return r >= 0 and r < 5 and c >= 0 and c < 5;
}

int dfs(int depth, int emptyRow, int emptyCol, int prevRow, int prevCol) {
    if (isFinal()) return depth;
    if (depth >= 11) return INF; // unsolvable within 10 moves
    int minMoves = INF;
    for (int i = 0; i < 8; i++) {
        int newR = emptyRow + rOff[i];
        int newC = emptyCol + cOff[i];
        if (!isValid(newR, newC) or (newR == prevRow and newC == prevCol)) continue;
        swap(grid[emptyRow][emptyCol], grid[newR][newC]);
        minMoves = min(minMoves, dfs(depth+1, newR, newC, emptyRow, emptyCol));
        swap(grid[emptyRow][emptyCol], grid[newR][newC]);
    }
    return minMoves;
}

void solve() {
    // read input
    grid.assign(5, vector<char>(5));
    int sr, sc;
    for (int i = 0; i < 5; i++) {
        string line; getline(cin, line);
        for (int j = 0; j < 5; j++) {
            grid[i][j] = line[j];
            if (grid[i][j] == ' ') {
                sr = i;
                sc = j;
            }
        }
    }

    int moves = dfs(0, sr, sc, -1, -1);
    if (moves > 10) {
        cout << "Unsolvable in less than 11 move(s)." << endl;
    } else {
        cout << "Solvable in " + to_string(moves) + " move(s)." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t; cin.ignore();
    while (t--) {
        solve();
    }
}