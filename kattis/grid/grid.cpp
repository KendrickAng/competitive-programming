#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dist;
int inf = 1e9;

void nxt(int r, int c, vector<pair<int,int>> &neighs) {
    int k = grid[r][c];
    neighs.push_back({r-k, c});
    neighs.push_back({r+k, c});
    neighs.push_back({r, c-k});
    neighs.push_back({r, c+k});
}

int main() {
    int rows, cols; cin >> rows >> cols;
    grid.assign(rows, vector<int>(cols));
    dist.assign(rows, vector<int>(cols, inf));

    // read input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c; cin >> c;
            grid[i][j] = stoi(string(1, c));
        }
    }

    // bfs
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        vector<pair<int,int>> neighs;
        nxt(r, c, neighs);
        for (auto [rr, cc]: neighs) {
            if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;
            if (dist[rr][cc] > dist[r][c] + 1) {
                dist[rr][cc] = dist[r][c] + 1;
                q.push({rr, cc});
            }
        }
    }

    int d = dist[rows-1][cols-1];
    cout << ((d == inf) ? -1 : d) << endl;
}