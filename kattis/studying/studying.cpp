#include <bits/stdc++.h>

using namespace std;
using ddd = tuple<double,double,double>;

const double EPS = 1e-8;

vector<ddd> funcs;
vector<double> xvals;
double n, t;

bool valid(double deriv) {
    double total = 0;
    for (int i = 0; i < funcs.size(); i++) {
        auto [a, b, c] = funcs[i];
        xvals[i] = max(0.0, (deriv-b)/(2*a));
        total += xvals[i];
    }
    return total <= t;
}

double calc(double a, double b, double c, double x) {
    return a*x*x + b*x + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    funcs.resize(n);
    xvals.resize(n);
    for (int i = 0; i < n; i++) {
        double a, b, c; cin >> a >> b >> c;
        funcs[i] = {a, b, c};
    }

    double lo = -1000;
    double hi = 1000;
    while (fabs(lo-hi) > EPS) {
        double mid = (lo + hi) / 2;
        if (valid(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = funcs[i];
        total += calc(a, b, c, xvals[i]);
    }
    cout << fixed << setprecision(10) << total/n << endl;
}