#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid(110, vector<char>(110));
unordered_map<char, pair<int,int>> coords;

void print() {
    int maxLeft = 1000;
    int maxRight = -1;
    int maxTop = 1000;
    int maxBtm = -1;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (grid[r][c] != ' ') {
                maxLeft = min(maxLeft, c);
                maxRight = max(maxRight, c);
                maxTop = min(maxTop, r);
                maxBtm = max(maxBtm, r);
            }
        }
    }

    for (int i = maxTop; i <= maxBtm; i++) {
        int rightmost = -1;
        for (int j = maxRight; j >= maxLeft; j--) {
            if (grid[i][j] != ' ') {
                rightmost = j;
                break;
            }
        }
        for (int j = maxLeft; j <= rightmost; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void init() {
    coords.clear();


    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            grid[i][j] = ' ';
        }
    }
    char ch = 'A';
    for (int r = 50; r < 55; r++) {
        for (int c = 50; c < 55; c++) {
            coords[ch] = {r, c};
            grid[r][c] = ch++;
        }
    }
}

void move(char ch, string dir) {
    auto [r, c] = coords[ch];
    // cout << r << " " << c << grid.size() << " " << grid[0].size() << endl;
    stack<char> todos;
    while (grid[r][c] != ' ') {
        todos.push(grid[r][c]);
        if (dir == "up") r--;
        else if (dir == "down") r++;
        else if (dir == "left") c--;
        else if (dir == "right") c++;
    }
    while (!todos.empty()) {
        char nxt = todos.top(); todos.pop();
        auto &[rr, cc] = coords[nxt];
        grid[rr][cc] = ' ';
        if (dir == "up")  {
            rr--;
        } else if (dir == "down") {
            rr++;
        } else if (dir == "left") {
            cc--;
        } else if (dir == "right") {
            cc++;
        }
        grid[rr][cc] = nxt;
    }
}

void solve(int n) {
    init();

    char ch;
    string dir;
    for (int i = 0; i < n; i++) {
        cin >> ch >> dir;
        move(ch, dir);
    }

    print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;

        solve(n);
    }
}