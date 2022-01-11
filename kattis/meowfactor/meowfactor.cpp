#include <bits/stdc++.h>

using namespace std;
using ll = long long;
double EPS = pow(10, -6);

int main() {
    long double n; cin >> n;
    int ans = 1;
    for (ll i = 2; i <= 128; i++) { // (2^63-1) ^ (1/9) = 128
        if (fmodl(n, powl(i, 9)) <= EPS) {
            ans = i;
        }
    }
    cout << ans << endl;
}