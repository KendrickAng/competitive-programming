// O(nS) solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int c, n;
vector<vector<int>> memo;
vector<int> weights;
vector<int> values;

int dp(int idx, int remW) {
    if ((idx == n) || (remW == 0)) {
        return 0;
    }
    int& ans = memo[idx][remW];
    if (ans != -1) return ans;
    if (weights[idx] > remW) {
        ans = dp(idx+1, remW);
    } else {
        ans = max(dp(idx+1, remW), values[idx] + dp(idx+1, remW-weights[idx]));
    }
    return ans;
}

vector<int> used;
void print(int idx, int cap) {
    if (idx == n || cap < 0) return;
    if (dp(idx+1, cap) == dp(idx, cap)) {
        print(idx+1, cap);
    } else {
        used.push_back(idx);
        print(idx+1, cap-weights[idx]);
    }
}

int main() {
    while (cin >> c >> n) {
        weights = vector<int>(n);
        values = vector<int>(n);
        used = vector<int>{};
        for (int i = 0; i < n; i++) cin >> values[i] >> weights[i];
        memo = vector<vector<int>>(n+10, vector<int>(c+10, -1));

        dp(0, c);
        print(0, c);

        cout << used.size() << endl;
        for (int i: used) {
            cout << i << " ";
        }
        cout << endl;

        // print out the entire dp table
        // for (auto a: memo) {
        //     for (auto b: a) {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
    }
}