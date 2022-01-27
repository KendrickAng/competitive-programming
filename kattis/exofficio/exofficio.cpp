#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
const int NORTH = 1;
const int EAST = 2;
const int SOUTH = 3;
const int WEST = 4;

int rows, cols;
vector<vector<char>> walls;
// vector<vector<bool>> visited;
vector<vector<int>> dist;
vector<iii> offsets;

void print() {
    for (int r = 0; r < walls.size(); r++) {
        int cSize = walls[r].size();
        for (int c = 0; c < cSize; c++) {
            cout << walls[r][c];
        }
        cout << endl;
    }
}

void printDist() {
    for (int r = 0; r < dist.size(); r++) {
        int cSize = dist[r].size();
        for (int c = 0; c < cSize; c++) {
            cout << dist[r][c] << ' ';
        }
        cout << endl;
    }
}

bool isValid(int row, int col) {
    return row >= 0 and row < rows and col >= 0 and col < cols;
}

void removeWall(int rfrom, int cfrom, int rto, int cto, int dir) {
    rfrom++; rto++;
    cfrom = (cfrom+1) * 2 - 1;
    cto = (cto+1) * 2 - 1;
    switch (dir) {
        case NORTH: {
            walls[rfrom-1][cfrom] = ' ';
            break;
        }
        case EAST: {
            walls[rfrom][cfrom+1] = ' ';
            break;
        }
        case SOUTH: {
            walls[rfrom][cfrom] = ' ';
            break;
        }
        case WEST: {
            walls[rfrom][cfrom-1] = ' ';
            break;
        }
    }
}

int main() {
    // srand(unsigned(time(0)));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> cols;
    // push in first row
    vector<char> firstRow;
    for (int i = 1; i <= 2 * cols; i++) {
        if (i % 2 == 0) firstRow.push_back('_');
        else firstRow.push_back(' ');
    }
    walls.push_back(firstRow);
    // push in the rest (r) rows
    for (int j = 0; j < rows; j++) {
        vector<char> row;
        // each row onwards should have 2c + 1 chars
        for (int i = 1; i <= 2 * cols + 1; i++) {
            if (i % 2 == 0) row.push_back('_');
            else row.push_back('|');
        }
        walls.push_back(row);
    }
    
    // initialise visited arr for bfs
    // visited.assign(rows, vector<bool>(cols, false));
    dist.assign(rows, vector<int>(cols, -1));

    // bfs from middle
    queue<iii> q;
    int rStart = rows/2;
    int cStart = cols/2;
    if (rows % 2 == 0 and cols % 2 != 0) {
        offsets = {
            {-1,0,NORTH},
            {1,0,SOUTH},
            {0,1,EAST},
            {0,-1,WEST},
        };
    } else {
        offsets = {
            {0,1,EAST},
            {0,-1,WEST},
            {-1,0,NORTH},
            {1,0,SOUTH},
        };
    }
    // if (rows % 2 == 0 and cols % 2 != 0) {
    //     rStart = rows/2 - 1;
    // }
    q.push({ rStart, cStart, 0 });
    dist[rStart][cStart] = 0;

    while (!q.empty()) {
        auto [currR, currC, currDist] = q.front(); q.pop();

        // random_shuffle(offsets.begin(), offsets.end());
        for (auto [rOff, cOff, dir]: offsets) {
            int newR = currR + rOff;
            int newC = currC + cOff;
            if (isValid(newR, newC) and dist[newR][newC] == -1) {
                removeWall(currR, currC, newR, newC, dir);
                dist[newR][newC] = currDist + 1;
                q.push({ newR, newC, currDist+1 });
            }
        }
    }

    print();
    // printDist();
}