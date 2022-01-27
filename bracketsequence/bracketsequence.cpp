#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll LBR = -1;
const ll RBR = -2;

void solve() {
    int n; cin >> n;

    bool isAdd = true;
    stack<ll> stk;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "(") {
            isAdd = !isAdd;
            stk.push(LBR);
        } else if (s == ")") {
            ll total = isAdd ?  0 : 1;
            while (stk.top() != LBR) {
                ll num = stk.top(); stk.pop();
                if (isAdd) {
                    total += num % MOD;
                    total %= MOD;
                } else {
                    total *= num % MOD;
                    total %= MOD;
                }
            }
            stk.pop(); // remove LBR
            stk.push(total);
            isAdd = !isAdd;
        } else {
            stk.push(stoll(s));
        }
    }

    ll ans = 0;
    while (!stk.empty()) {
        ll num = stk.top(); stk.pop();
        ans += num % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}