#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 2010;
const int MAX_W = 2010;

int N, W[MAX_N], V[MAX_N], memo[MAX_N][MAX_W];
vector<int> idxs;

void print(int i, int j) {
    if (memo[i][j] == 0) return;
    if (memo[i][j] != memo[i-1][j]) {
        idxs.push_back(i-1);
        print(i-1, j-W[i]);
    } else {
        print(i-1, j);
    }
}

int main() {
    int C, N;
    while (cin >> C >> N) {
        memset(W, 0, N + 10);
        memset(V, 0, N + 10);
        memset(memo, 0, sizeof memo);

        for (int i = 0; i <= N; i++) memo[i][0] = 0; // 0 capacity - can't take anything
        for (int i = 0; i <= C; i++) memo[0][i] = 0; // 0 items - can't take anything
        for (int i = 1; i <= N; i++) cin >> V[i] >> W[i];
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= C; c++) {
                if (W[r] > c) memo[r][c] = memo[r-1][c];
                else          memo[r][c] = max(memo[r-1][c], V[r]+memo[r-1][c-W[r]]);
            }
        }
        // cout << "max value is: " << memo[N][C] << endl;

        // //print the table
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= C; j++) {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        idxs = vector<int>{};
        print(N, C);
        cout << idxs.size() << endl;
        for (auto a: idxs) cout << a << " ";
        cout << endl;
    }
}