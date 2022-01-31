#include <bits/stdc++.h>

using namespace std;

#define DEBUG false
#define debug(x) {if (DEBUG) {cout << "line " << __LINE__ << ": " << x << endl;}}
#define var(x) {cout << #x << " = " << x << " " << endl;}
#define endl '\n'

const double EPS = 1e-8;
const int KMAX = 9;

int f(int x, int k) {
    if (k == 0) return x;
    double ans = x;
    for (int i = 0; i < k; i++) {
        ans = 10.0 * pow(ans, 0.5);
    }
    return ceil(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, yLow, yHigh; cin >> x >> yLow >> yHigh;

    int low = -1;
    int high = -1;
    for (int k = 0; k <= KMAX; k++) {    
        int result = f(x, k);
        // var(k);
        // var(result);

        if (low == -1 && result >= yLow) low = k;
        if (result >= yLow && result <= yHigh) high = k;

        // exceeded range
        if (result > yHigh) break;
    }

    if (low == -1 || high == -1) cout << "impossible" << endl;
    else if (high == KMAX) cout << low << " inf" << endl;
    else cout << low << ' ' << high << endl;
}