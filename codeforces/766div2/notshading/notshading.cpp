#include <bits/stdc++.h>

using namespace std;

void solve() {
    int rows, cols, r, c; cin >> rows >> cols >> r >> c;
    r--; c--;
    bool hasBlack = false;
    vector<vector<char>> board(rows, vector<char>(cols));
    for (int rr = 0; rr < rows; rr++) {
        for (int cc = 0; cc < cols; cc++) {
            cin >> board[rr][cc];
            if (board[rr][cc] == 'B') hasBlack = true;
        }
    }

    if (!hasBlack) {
        cout << -1 << endl;
        return;
    }

    if (board[r][c] == 'B') {
        cout << 0 << endl;
        return;
    }

    bool blackBeside = false;
    for (int r2 = r; r2 >= 0; r2--) {
        if (board[r2][c] == 'B') {
            cout << 1 << endl;
            return;
        } 
    }
    for (int r2 = r; r2 < rows; r2++) {
        if (board[r2][c] == 'B') {
            cout << 1 << endl;
            return;
        }
    }
    for (int c2 = c; c2 >= 0; c2--) {
        if (board[r][c2] == 'B') {
            cout << 1 << endl;
            return;
        }
    }
    for (int c2 = c; c2 < cols; c2++) {
        if (board[r][c2] == 'B') {
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}