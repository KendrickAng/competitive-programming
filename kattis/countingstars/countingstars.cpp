#include <iostream>
#include <vector>

using namespace std;

int caseNum = 1;

bool isValid(vector<vector<char>> &arr, int r, int c) {
    return r >= 0 && r < arr.size() && c >= 0 && c < arr[0].size();
}

void flood(vector<vector<char>> &arr, int r, int c) {
    if (!isValid(arr, r, c)) return;
    if (arr[r][c] == '#') return;
    int rOff[]{ -1, 0, 1, 0 };
    int cOff[]{ 0, 1, 0, -1 };
    arr[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        flood(arr, r + rOff[i], c + cOff[i]);
    }
}

void solve(int rows, int cols) {
    vector<vector<char>> arr(rows, vector<char>(cols));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> arr[r][c];
        }
    }

    int ans = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (arr[r][c] == '-') {
                flood(arr, r, c);
                ans++;
            }
        }
    }

    cout << "Case " << caseNum++ << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    while (cin >> r >> c) {
        solve(r, c);
    }
}