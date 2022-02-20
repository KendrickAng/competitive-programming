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

int ar, ac, tr, tc;
vector<vector<bool>> grid;
vector<vector<int>> countLeft;
vector<vector<int>> countTile;

int count(int r, int c) {
    int ret = 0;
    for (int i = r; i < ar+tr; i += tr) {
        for (int j = c; j < ac+tc; j += tc) {
            if (countTile[i][j] > 0) ret++;
        }
    }
    return ret;
}

void solve() {
    grid.assign(ar, vector<bool>(ac));
    countLeft.assign(ar+tr, vector<int>(ac+tc, 0));
    countTile.assign(ar+tr, vector<int>(ac+tc, 0));
    for (int r = 0; r < ar; r++) {
        for (int c = 0; c < ac; c++) {
            char tmp; cin >> tmp;
            grid[r][c] = tmp == 'X';
        }
    }

    for (int i = 0; i < ar+tr; i++) {
        int currCount = 0;
        for (int j = 0; j < ac+tc; j++) {
            // count the number of pixels to the left to fill within one tile length left
            if (i < ar and j < ac and grid[i][j]) currCount++;
            if (i < ar and j-tc >= 0 and grid[i][j-tc]) currCount--;
            countLeft[i][j] = currCount;
        }
    }
    // debug(countLeft);

    for (int j = 0; j < ac+tc; j++) {
        int currCount = 0;
        for (int i = 0; i < ar+tr; i++) {
            // count the number of pixels to fill within one tile length left AND up
            currCount += countLeft[i][j];
            if (i-tr >= 0) currCount -= countLeft[i-tr][j];
            countTile[i][j] = currCount;
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < tr; i++) {
        for (int j = 0; j < tc; j++) {
            result = min(result, count(i, j));
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> ar >> ac >> tr >> tc) solve();
}