#include <bits/stdc++.h>

using namespace std;
using ld = double;

#define var(x) {cout << #x << " = " << x << " " << endl;}

const double EPS = 1e-6;

void solve() {
    int id, maxDenom;
    ld x;
    cin >> id >> maxDenom >> x;

    int currNum = -1;
    int currDen = -1;
    ld currAns = -1;
    ld currErr = -1;

    for (int denom = maxDenom/2; denom <= maxDenom; denom++) {
        int numer = (int) (x * denom + 0.5);

        ld frac = (ld) numer / denom;
        if (currAns == -1 || fabs(x - frac) <= currErr) {
            currAns = frac;
            currNum = numer;
            currDen = denom;
            currErr = fabs(x - currAns);
        }
    }

    int gcd = __gcd(currNum, currDen);
    cout << id << ' ' << currNum/gcd << '/' << currDen/gcd << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
