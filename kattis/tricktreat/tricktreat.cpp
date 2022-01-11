#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
using dd = pair<double, double>;

double f(double x, dd houses[], int n) {
    // assume y = 0
    double ans = -1;
    for (int i = 0; i < n; i++) {
        double xx = houses[i].first - x;
        double yy = houses[i].second - 0;
        ans = max(ans, sqrt(xx*xx + yy*yy));
    }
    return ans;
}

void solve(int n) {
    dd houses[n];
    for (int i = 0; i < n; i++) {
        cin >> houses[i].first >> houses[i].second;
    }
    double hi = 200000;
    double lo = -200000;
    double EPS = 1e-9;
    while (fabs(hi-lo) > EPS) {
        // cout << "HI " << hi << "LO " << lo << endl;
        double delta = (hi-lo)/3.0;
        double m1 = lo+delta;
        double m2 = hi-delta;
        (f(m1, houses, n) > f(m2, houses, n)) ? lo = m1 : hi = m2;
    }
    cout << fixed << setprecision(10) << lo << " " << f(lo, houses, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }
}