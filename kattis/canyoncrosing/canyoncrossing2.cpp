#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

// TODO: explore varargs
#define var(x) {cout << #x << " = " << x << " " << endl;}

int MAXN = 1000;

int rows, cols, bridges;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));
vector<vector<bool>> seen;

vector<int> rOff = {1,0,0,-1};
vector<int> cOff = {0,-1,1,0};

bool canCross(int minHeight) {
    seen.assign(rows, vector<bool>(cols, false));
    queue<iii> curr, next;
    for (int cStart = 0; cStart < cols; cStart++) {
        if (grid[0][cStart] >= minHeight) {
            curr.push({0, 0, cStart});
        } else {
            next.push({1, 0, cStart}); // one bridge
        }
        seen[0][cStart] = true;
    }

    while (!curr.empty() || !next.empty()) {
        queue<iii> &q = (curr.empty() ? next : curr);
        auto [bUsed, r, c] = q.front(); q.pop();
        if (r == rows-1 && bUsed <= bridges) return true;
        // cout << r << ' ' << c << ' ' << bUsed << endl;

        for (int i = 0; i < 4; i++) {
            int rr = r + rOff[i];
            int cc = c + cOff[i];
            if (rr < 0 || rr >= rows || cc < 0 || cc >= cols || seen[rr][cc]) continue;

            seen[rr][cc] = true;
            if (grid[rr][cc] >= minHeight) {
                if (rr == rows-1 && bUsed <= bridges) return true;
                curr.push({bUsed,rr,cc});
            } else {
                if (rr == rows-1 && bUsed+1 <= bridges) return true;
                next.push({bUsed+1,rr,cc});
            }
        }
    }

    return false;
}


void solve() {
    cin >> rows >> cols >> bridges;
    int lo = 1e9;
    int hi = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            lo = min(lo, grid[i][j]);
            hi = max(hi, grid[i][j]);
        }
    }

    int lastAns = lo;
    while (lo <= hi) {
        int mid = hi + (lo-hi)/2;
        // var(mid);
        if (canCross(mid)) {
            lastAns = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    cout << lastAns << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
