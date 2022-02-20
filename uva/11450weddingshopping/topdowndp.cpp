#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

const int MAXM = 210;
const int MAXC = 30;
vector<vector<int>> memo;
vector<vector<int>> price;
int m, c;

const int INF = 1e9;

void printMemo() {
    for (auto a: memo) {
        for (auto b: a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}

int dp(int gIdx, int mLeft) {
    if (mLeft < 0) return -INF;
    if (gIdx == c) return m - mLeft; // money spent
    // cout << "GIdx " << gIdx << ' ' << "mLeft " << mLeft << endl;
    int &ans = memo[gIdx][mLeft];
    if (ans == -1) {
        for (int spent: price[gIdx]) {
            ans = max(ans, dp(gIdx+1, mLeft-spent));
        }
    }
    return ans;
}

void solve() {
    cin >> m >> c;
    memo.assign(MAXC, vector<int>(MAXM, -1));
    price.assign(MAXC, vector<int>());
    for (int i = 0; i < c; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            price[i].push_back(tmp);
        }
    }

    int ans = dp(0, m);

    if (ans < 0) cout << "no solution" << endl;
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
