#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr; // base honeycomb
vector<vector<bool>> occupied; // whether occupied or not
vector<pair<int,int>> mapping; // maps index to coordinate in honeycomb grid
int ans = 0;

void print() {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int newR, int newC) {
    return newR >= 0 && newR < arr.size() && newC >= 0 && newC < arr[0].size();
}

void flood(int r, int c) {
    arr[r][c] = -1;
    vector<pair<int,int>> offsets = {{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};
    if (occupied[r][c]) {
        for (auto [rr, cc]: offsets) {
            if (!isValid(r+rr, c+cc)) ans++;
        }
    } else {
        for (auto [rr, cc]: offsets) {
            int newR = r + rr;
            int newC = c + cc;
            if (isValid(newR, newC)) {
                if (occupied[newR][newC]) {
                    ans++;
                } else if (arr[newR][newC] != -1) {
                    flood(newR, newC);
                }
            }
        }
    }
}


int main() {
    int r, k; cin >> r >> k;
    int n = r * 2 - 1;
    
    arr.assign(n, vector<int>(n, -2));
    occupied.assign(n, vector<bool>(n, false));
    mapping.push_back({-1, -1}); // dummy

    int id = 1;
    for (int i = 0; i < r-1; i++) {
        for (int j = 0; j < r+i; j++) {
            arr[i][j] = id++;
            mapping.push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        arr[r-1][i] = id++;
        mapping.push_back({r-1, i});
    }
    int offset = 1;
    for (int i = r; i < n; i++) {
        for (int j = i-r+1; j < n; j++) {
            arr[i][j] = id++;
            mapping.push_back({i, j});
        }
    }

    // print();

    for (int i = 0; i < k; i++) {
        int idx; cin >> idx;
        auto [r, c] = mapping[idx];
        occupied[r][c] = true;
    }

    // flood fill from the outside
    for (int i = 0; i < n; i++) {
        if (arr[0][i] != -1) flood(0, i);
        if (arr[n-1][i] != -1) flood(n-1, i);
        if (arr[i][0] != -1) flood(i, 0);
        if (arr[i][n-1] != -1) flood(i, n-1);
    }

    cout << ans << endl;
}