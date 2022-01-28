#include <bits/stdc++.h>

using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using iii = tuple<int,int,int>;

vvi grid;
vector<vector<bool>> seen;
vector<int> rOff = {-1,1,0,0};
vector<int> cOff = {0,0,1,-1};
int rows, cols;
bool floodedLower;
int blocks;
int height;

void dfs(int r, int c) {
    blocks++;
    seen[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int rr = r + rOff[i];
        int cc = c + cOff[i];
        if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;
        if (grid[rr][cc] > height) continue; // cannot move up
        if (grid[rr][cc] < height) floodedLower = true; // stop 
        if (!seen[rr][cc]) dfs(r+rOff[i], c+cOff[i]);
    }
}

void print(vector<vector<bool>> arr) {
    for (auto a: arr) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cols >> rows;
    grid.assign(rows, vi(cols));
    vector<iii> order;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
            order.push_back({ grid[r][c], r, c });
        }
    }

    sort(order.begin(), order.end());

    seen.assign(rows, vector<bool>(cols, false));
    int ccs = 0;
    for (int i = 0; i < order.size(); i++) {
        auto [height, r, c] = order[i];
        if (!seen[r][c])  {
            floodedLower = false;
            blocks = 0;
            height = grid[r][c];
            // cout << r << " " << c << endl;
            dfs(r, c);
            if (!floodedLower) ccs += blocks;
            // print(seen);
            // if (floodedLower) cout << "floodedLower" << endl;
        }
    }

    cout << ccs << endl;
}