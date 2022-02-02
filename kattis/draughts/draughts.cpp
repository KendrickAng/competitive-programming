#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define var(x) {cout << #x << " = " << x << " " << endl;}

vector<vector<char>> v;

int backtrack(int x, int y) {
    int score = 0;

    if(x+2 < 10 && y+2 < 10) {
        if(v[x+1][y+1] == 'B') {
            if(v[x+2][y+2] == '.') {
                v[x][y] = '.';
                v[x+1][y+1] = '.';
                v[x+2][y+2] = 'W';
                score = max(score, 1 + backtrack(x+2,y+2));
                v[x][y] = 'W';
                v[x+1][y+1] = 'B';
                v[x+2][y+2] = '.';
            }
        }
    }

    if(x-2 >= 0 && y+2 < 10) {
        if(v[x-1][y+1] == 'B') {
            if(v[x-2][y+2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x-1][y+1] = '.';
                v[x-2][y+2] = 'W';
                score = max(score, 1 + backtrack(x-2,y+2));
                v[x][y] = 'W';
                v[x-1][y+1] = 'B';
                v[x-2][y+2] = '.';
            }
        }
    }

    if(x+2 < 10 && y-2 >= 0) {
        if(v[x+1][y-1] == 'B') {
            if(v[x+2][y-2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x+1][y-1] = '.';
                v[x+2][y-2] = 'W';
                score = max(score, 1 + backtrack(x+2,y-2));
                v[x][y] = 'W';
                v[x+1][y-1] = 'B';
                v[x+2][y-2] = '.';
            }
        }
    }

    if(x-2 >= 0 && y-2 >= 0) {
        if(v[x-1][y-1] == 'B') {
            if(v[x-2][y-2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x-1][y-1] = '.';
                v[x-2][y-2] = 'W';
                score = max(score, 1 + backtrack(x-2,y-2));
                v[x][y] = 'W';
                v[x-1][y-1] = 'B';
                v[x-2][y-2] = '.';
            }
        }
    }

    return score;
}

int solve() {
    vector<ii> whites;
    v.assign(10, vector<char>(10));
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            char chr; cin >> chr;
            v[r][c] = chr;
            if (v[r][c] == '#') v[r][c] = '.';
            if (chr == 'W') whites.push_back({r, c});
        }
    }

    // no light pieces - exit
    if (whites.empty()) return 0;

    int ans = 0;
    for (auto [r, c]: whites) {
        ans = max(ans, backtrack(r, c));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) cout << solve() << endl;
}
