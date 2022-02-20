#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}

const int MAXM = 210;
const int MAXC = 30;
vector<vector<bool>> reachable;
vector<vector<int>> price;
int m, c;

const int INF = 1e9;

void solve() {
    cin >> m >> c;
    reachable.assign(MAXC, vector<bool>(MAXM, false));
    price.assign(MAXC, vector<int>{});

    // read prices
    for (int i = 0; i < c; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            price[i].push_back(tmp);
        }
    }

    // initialize base cases
    for (int i = 0; i < price[0].size(); i++) {
        if (m - price[0][i] >= 0) reachable[0][m - price[0][i]] = true;
    }

    // perform dp
    for (int line = 1; line < price.size(); line++) {
        for (int model = 0; model < price[line].size(); model++) {
            int cost = price[line][model];
            for (int money = 0; money <= m; money++) {
                if (reachable[line-1][money] && money-cost >= 0) {
                    reachable[line][money-cost] = true;
                }
            }
        }
    }

    // debug
    // for (int i = 0; i < c; i++) {
    //     for (int j = 0; j < m; j++)  cout << reachable[i][j] << ' ';
    //     cout << endl;
    // }

    // check answer
    int ans = -1;
    for (int col = 0; col <= m; col++) {
        if (reachable[c-1][col]) {
            ans = m - col;
            break;
        }
    }
    if (ans != -1) cout << ans << endl;
    else cout << "no solution" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
