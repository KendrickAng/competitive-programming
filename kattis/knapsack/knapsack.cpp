#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;
vector<bool> chosen;
vector<int> weights;
vector<int> values;

int dp(int idx, int remW, int n) {
    if ((idx == n) || (remW == 0)) {
        return 0;
    }
    int ans = memo[idx][remW];
    if (ans != -1) return ans;
    // no choice, skip
    if (weights[idx] > remW) {
        memo[idx][remW] = dp(idx+1, remW, n);
    }
    // have choice, skip or take
    else {
        int ans1 = dp(idx+1, remW, n);
        int ans2 = values[idx] + dp(idx+1, remW-weights[idx], n);
        chosen[idx] = ans2 > ans1;
        cout << "idx " << idx << " is " << ((ans2>ans1) ? "chosen" : "not chosen") << endl;
        memo[idx][remW] = max(ans1, ans2);
    }
    return memo[idx][remW];
}

int main() {
    int c, n;
    while (cin >> c >> n) {
        chosen.resize(n, false);
        weights.resize(n);
        values.resize(n);
        for (int i = 0; i < n; i++) cin >> values[i] >> weights[i];
        memo.resize(n, vector<int>(c+10, -1));
        cout << "value is " << dp(0, c, n) << endl;

        int taken = 0;
        for (int i = 0; i < n; i++) if (chosen[i]) taken++;
        cout << taken << endl;
        for (int i = 0; i < n; i++) if (chosen[i]) cout << i << " ";
        cout << endl;
    }
}