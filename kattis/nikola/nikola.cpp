#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1010;
const int MAX_INT = 1e9;
vector<vector<int>> memo(MAX_N, vector<int>(MAX_N, -1)); // square idx, current jump length
vector<int> fees;
int n;

bool isValid(int pos) {
    return pos >= 1 && pos <= n;
}

// returns the min cost to reach this state given it took lastJump steps to get here
int dp(int pos, int lastJump) {
    if (pos == 1 && lastJump == 0) return 0;
    if (pos == 2 && lastJump == 1) return fees[pos];
    if (lastJump < 1) return MAX_INT;
    int &ans = memo[pos][lastJump];
    if (ans != -1) return ans;

    int afterFront = MAX_INT;
    int afIdx = pos - lastJump;
    if (isValid(afIdx)) afterFront = fees[pos] + dp(afIdx, lastJump-1);

    int afterBack = MAX_INT;
    int abIdx = pos + lastJump;
    if (isValid(abIdx)) afterBack = fees[pos] + dp(abIdx, lastJump);

    return ans = min(afterBack, afterFront);
}

// int dp(int idx, int jumpLen) {
//     if (idx == 1) return 0; // min cost to get to square 1 is 0
//     if (idx == 2) return fees[idx]; // min cost to get to square 2 is 1 (first jump)
//     int &ans = memo[idx][jumpLen];
//     if (ans != -1) return ans;
//     // forward or backward
//     int back = MAX_INT;
//     int backIdx = idx-jumpLen;
//     if (backIdx >= 1 && backIdx <= n) back = dp(backIdx, jumpLen) + fees[backIdx];

//     int forward = MAX_INT;
//     int forwardIdx = idx + jumpLen + 1;
//     if (forwardIdx >= 1 && forwardIdx <= n) forward = dp(forwardIdx, jumpLen+1) + fees[forwardIdx];
    
//     return ans = min(forward, back);
// }

int main() {
    cin >> n;
    fees.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> fees[i]; // 1-indexed for easier readability
    for (int i = 1; i <= n; i++) dp(n, i);
    int ans = MAX_INT;
    for (int i = 1; i <= n; i++) ans = min(ans, memo[n][i]);
    cout << ans << endl;
}