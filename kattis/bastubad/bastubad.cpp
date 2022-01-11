#include <bits/stdc++.h>

using namespace std;

double f(double a, double b, double c, double x) {
    return a*x*x + b*x + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<tuple<int,int,int,int>> finns;
    for (int i = 0; i < n; i++) {
        int a, b, c, t; cin >> a >> b >> c >> t;
        finns.emplace_back(t, a, b, c);
    }

    // sort by decreasing t
    sort(finns.rbegin(), finns.rend());
    // for (auto &[t, a, b, c]: finns) {
    //     cout << a << " " << b << " " << c << " " << t << endl;
    // }

    double ans = 0;
    double aSum = 0;
    double bSum = 0;
    double cSum = 0;
    for (auto &[t, a, b, c]: finns) {
        aSum += a;
        bSum += b;
        cSum += c;
        double ans1 = f(aSum, bSum, cSum, 0.0);
        double ans2 = f(aSum, bSum, cSum, t);
        ans = max(ans, max(ans1, ans2));

        // ax^2 + bx + c, avoid division by zero
        if (aSum != 0) {
            double x = -bSum / (2 * aSum);
            if (x > 0.0 && x <= t) {
                double ans3 = f(aSum, bSum, cSum, x);
                ans = max(ans, ans3);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}