#include <bits/stdc++.h>

using namespace std;

struct Cube {
    int top = 1;
    int btm = 2;
    int front = 3;
    int back = 4;
    int left = 5;
    int right = 6;
};

Cube rotateLeft(Cube c) {
    Cube ret;
    ret.front = c.front;
    ret.back = c.back;
    ret.left = c.top;
    ret.top = c.right;
    ret.right = c.btm;
    ret.btm = c.left;
    return ret;
}

Cube rotateDown(Cube c) {
    Cube ret;
    ret.left = c.left;
    ret.right = c.right;
    ret.top = c.front;
    ret.front = c.btm;
    ret.btm = c.back;
    ret.back = c.top;
    return ret;
}

Cube rotateRight(Cube c) {
    return rotateLeft(rotateLeft(rotateLeft(c)));
}

Cube rotateUp(Cube c) {
    return rotateDown(rotateDown(rotateDown(c)));
}

// up, down, left, right
vector<pair<int,int>> offset = {{-1,0},{1,0},{0,-1},{0,1}};

void flood(vector<vector<char>> &arr, int r, int c, Cube cube, set<int> &sides) {
    if (r < 0 || r >= 6 || c < 0 || c >= 6 || arr[r][c] != '#') return;
    arr[r][c] = 'X';
    sides.insert(cube.btm);
    for (int i = 0; i < 4; i++) {
        auto &[rOff, cOff] = offset[i];
        int nextR = r + rOff;
        int nextC = c + cOff;
        if (i == 0) flood(arr, nextR, nextC, rotateUp(cube), sides);
        else if (i == 1) flood(arr, nextR, nextC, rotateDown(cube), sides);
        else if (i == 2) flood(arr, nextR, nextC, rotateLeft(cube), sides);
        else if (i == 3) flood(arr, nextR, nextC, rotateRight(cube), sides);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> arr(6, vector<char>(6));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            if (arr[r][c] == '#') {
                set<int> sides;
                Cube cube;
                flood(arr, r, c, cube, sides);
                if (sides.size() == 6) {
                    cout << "can fold" << endl;
                } else {
                    cout << "cannot fold" << endl;
                }
                return 0;
            }
        }
    }
}