#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>; // days to reach, remaining stamina
using iiii = tuple<int,int,int,int>;

const ii INF = {1e9, -1e9};

struct classcomp {
    bool operator() (const iiii &a, const iiii &b) const {
        auto [a1, a2, a3, a4] = a;
        auto [b1, b2, b3, b4] = b;
        if (a1 != b1) return a1 < b1;
        else if (a2 != b2) return a2 > b2;
        else if (a3 != b3) return a3 < b3;
        else return a4 < b4;
    }
};

void sssp(int n, int m, int k, vector<vector<char>> &grid, ii start, ii end) {
    vector<vector<ii>> dist(n, vector<ii>(m, INF));
    set<iiii, classcomp> pq;
    dist[start.first][start.second] = { 1, k };
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            pq.insert({ dist[r][c].first, dist[r][c].second, r, c });
        }
    }

    // sssp
    vector<int> rowOff = {-1,1,0,0};
    vector<int> colOff = {0,0,-1,1};
    while (!pq.empty()) {
        auto [days, stamina, r, c] = *pq.begin();
        pq.erase(pq.begin());
        for (int i = 0; i < 4; i++) {
            int rr = r + rowOff[i];
            int cc = c + colOff[i];

            if (rr < 0 || rr >= n || cc < 0 || cc >= m || grid[rr][cc] == '#') continue;

            auto [currDays, currStamina] = dist[r][c];
            char terrain = grid[rr][cc];
            int staminaNeed;
            if (terrain == 'S' || terrain == '.' || terrain == 'G') {
                staminaNeed = 1;
            } else if (terrain == 'F') {
                staminaNeed = 2;
            } else if (terrain == 'M') {
                staminaNeed = 3;
            }
            if (currStamina < staminaNeed) {
                currDays++;
                currStamina = k;
            }
            if (currStamina < staminaNeed) continue; // not enough stamina even when rested
            currStamina -= staminaNeed;

            auto [nxtDays, nxtStamina] = dist[rr][cc];
            if (currDays > nxtDays || (currDays == nxtDays && currStamina <= nxtStamina)) continue;
            // cout << "relax " << rr << " " << cc << " currDays " << currDays << " currStam "<< currStamina<<endl;
            pq.erase(pq.find({ dist[rr][cc].first, dist[rr][cc].second, rr, cc }));
            dist[rr][cc] = { currDays, currStamina };
            pq.insert({ dist[rr][cc].first, dist[rr][cc].second, rr, cc });
        }
    }

    if (dist[end.first][end.second] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[end.first][end.second].first << endl;
    }
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    ii start, end;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'S') start = {r, c};
            if (grid[r][c] == 'G') end = {r, c};
        }
    }
    sssp(n, m, k, grid, start, end);
}