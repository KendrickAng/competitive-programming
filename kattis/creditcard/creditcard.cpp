#include <bits/stdc++.h>

using namespace std;
using ld = double;
using ll = long long;

const double eps = 1e-8;
const double maxBal = 50000;
const int maxPayments = 1200;

void solve() {
    ld mthRate, bal, amt;
    cin >> mthRate >> bal >> amt;
    ld balLimit = maxBal + 1;

    int payments = 0;
    while (bal > 0 and payments++ <= maxPayments and bal < balLimit ) {
        // add monthly rate to balance, round interest to nearest cent
        bal *= (1 + mthRate / 100.0);
        bal = (ll) (bal * 100 + 0.5 + eps) / 100.0;
        bal -= amt;
    }

    if (bal >= balLimit || payments > maxPayments) {
        cout << "impossible" << endl;
    } else {
        cout << payments << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}