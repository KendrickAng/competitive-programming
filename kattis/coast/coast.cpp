#include <bits/stdc++.h>

using namespace std;

int rows, cols;
vector<vector<char>> grid;
int coast = 0;

vector<int> rOff = {-1,1,0,0};
vector<int> cOff = {0,0,-1,1};

void dfs(int r, int c) {
    grid[r][c] = 'X';
    for (int i = 0; i < 4; i++) {
        int rr = r + rOff[i];
        int cc = c + cOff[i];
        if (rr < 1 || rr >= rows-1 || cc < 1 || cc >= cols-1 || grid[rr][cc] == 'X') continue;
        if (grid[rr][cc] == '1') {
            coast++;
            continue;
        }
        dfs(rr, cc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> rows >> cols;
    rows += 2;
    cols += 2;
    grid.assign(rows, vector<char>(cols, '0'));
    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < cols-1; j++) {
            cin >> grid[i][j];
        }
    }

    for (int r = 1; r < rows-1; r++) if (grid[r][0] == '0') dfs(r, 0);
    for (int r = 1; r < rows-1; r++) if (grid[r][cols-1] == '0') dfs(r, cols-1);
    for (int c = 1; c < cols-1; c++) if (grid[0][c] == '0') dfs(0, c);
    for (int c = 1; c < cols-1; c++) if (grid[rows-1][c] == '0') dfs(rows-1, c);

    cout << coast << endl;
}