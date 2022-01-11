#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C, K; cin >> R >> C >> K;
    K -= 2; // account for the frame
    vector<vector<char>> arr(R, vector<char>(C));
    vector<vector<int>> arr2(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                arr2[i][j] = 1;
            } else {
                arr2[i][j] = 0;
            }
            if (j > 0) arr2[i][j] += arr2[i][j-1]; // pre-processing
        }
    }
    int maxLeft = -1;
    int maxRight = -1;
    int maxUp = -1;
    int maxDown = -1;
    int maxSubRect = -1;
    for (int l = 0; l < C; l++) {
        for (int r = 0; r < C; r++) {
            if (r-l+1 > K-2) continue;

            int subRect = 0;
            int localUp = 0;
            for (int row = 0; row < R; row++) {
                // Max 1D range sum on colums of this row
                if (l > 0) subRect += arr2[row][r] - arr2[row][l-1];
                else subRect += arr2[row][r];
                // Kadane's algorithm on rows
                if (subRect < 0 || (row-localUp+1) > K-2) {
                    subRect = 0;
                    localUp = row+1;
                }
                if (subRect > maxSubRect && (r-l+1) <= K-2 && (row-localUp+1) <= K-2) {
                    cout << subRect << endl;
                    maxSubRect = subRect;
                    maxLeft = l;
                    maxRight = r;
                    maxUp = localUp;
                    maxDown = row;
                }
            }
        }
    }
    cout << maxUp << maxDown << maxLeft << maxRight << endl;
}