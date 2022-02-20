#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

// TODO: explore varargs
#define var(x) {cout << #x << " = " << x << " " << endl;}

int MAXN = 1000;

int rows, cols, bridges;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));
vector<vector<vector<bool>>> seen;

vector<int> rOff = {1,0,0,-1};
vector<int> cOff = {0,-1,1,0};

// TODO: try dfs instead
bool dfs(int r, int c, int b, int minHeight) {
    if (r == rows-1) return true;
    seen[r][c][b] = true;
    bool ans = false;
    for (int i = 0; i < 4; i++) {
        int rr = r + rOff[i];
        int cc = c + cOff[i];
        if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;

        if (grid[rr][cc] >= minHeight && !seen[rr][cc][b]) {
            ans = ans || dfs(rr, cc, b, minHeight);
        } else if (grid[rr][cc] < minHeight && b > 0 && !seen[rr][cc][b-1]) {
            ans = ans || dfs(rr, cc, b-1, minHeight);
        } 
    }
    return ans;
}

bool canCross(int minHeight) {
    seen.assign(rows, vector<vector<bool>>(cols, vector<bool>(bridges+1, false)));
    bool ans = false;
    for (int cStart = 0; cStart < cols; cStart++) {
        if (grid[0][cStart] >= minHeight) {
            seen[0][cStart][bridges] = true;
            ans = ans || dfs(0, cStart, bridges, minHeight);
        } else if (bridges > 0) {
            seen[0][cStart][bridges-1] = true;
            ans = ans || dfs(0, cStart, bridges-1, minHeight);
        }
        if (ans) break;
    }
    return ans;
}

// bool canCross(int minHeight) {
//     queue<iii> q;
//     for (int cStart = 0; cStart < cols; cStart++) {
//         if (grid[0][cStart] >= minHeight) {
//             q.push({0, cStart, bridges});
//             seen[0][cStart][bridges] = true;
//         } else if (bridges > 0) {
//             q.push({0, cStart, bridges-1}) ;
//             seen[0][cStart][bridges-1] = true;
//         }
//     }
//     while (!q.empty()) {
//         auto [r, c, bLeft] = q.front(); q.pop();

//         // cout << r << ' ' << c << ' ' << bLeft << endl;
//         if (r == rows-1) return true;

//         for (int i = 0; i < 4; i++) {
//             int rr = r + rOff[i];
//             int cc = c + cOff[i];
//             if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;

//             if (grid[rr][cc] >= minHeight && !seen[rr][cc][bLeft]) {
//                 seen[rr][cc][bLeft] = true;
//                 q.push({rr,cc,bLeft});
//             } else if (grid[rr][cc] < minHeight && bLeft > 0 && !seen[rr][cc][bLeft-1]) {
//                 seen[rr][cc][bLeft-1] = true;
//                 q.push({rr,cc,bLeft-1});
//             } else {
//                 // can't cross, stop here
//             }
//         }
//     }

//     return false;
// }

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
