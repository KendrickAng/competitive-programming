#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

const double EPS = 1e-12;

int k, n;
vector<int> poles;

pair<bool,int> check(double minLen) {
    int used = 0;
    int cuts = 0;
    for (int i = 0; i < k; i++) {
        int pole = poles[i];
        int numPoles = pole / minLen;

        used += numPoles;
        cuts += numPoles-1;
        if (pole - numPoles*minLen >= 1e-8) cuts++;
    }
    return {used >= n, cuts};
}

void solve() {
    cin >> k >> n;
    poles.resize(k);
    for (int i = 0; i < k; i++) cin >> poles[i];

    double lo = 0.0;
    double hi = *max_element(poles.begin(), poles.end());
    int ans = -1;
    while (fabs(hi - lo) >= EPS) {
        double mid = (lo + hi) / 2.0;
        auto [isOk, cuts] = check(mid);
        if (isOk) {
            ans = cuts;
            lo = mid; // increase size of min pole
        } else {
            hi = mid;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
