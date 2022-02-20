#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

#define var(x) {cout << #x << " = " << x << " " << endl;}

const ll MAX = 2 * 1e5 * 1e9;

void solve() {
    int n; cin >> n;
    vector<ll> sum(n+1);
    vector<ll> mult(n+1);
    sum[0] = 0;
    mult[0] = 1;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        sum[i+1] = sum[i] + tmp;
        mult[i+1] = (mult[i] == -1 || mult[i] * tmp > MAX) ? -1 : mult[i] * tmp;   
    }

    int ans = 0;
    int maxN = sum.size();
    for (int j = 2; j < maxN; j++) {
        if (mult[j] == -1) break;
        for (int i = 0; i <= j-2; i++) {
            ll sumRange = sum[j] - sum[i];
            ll multRange = mult[j] / mult[i];
            if (sumRange == multRange) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    solve();
}
