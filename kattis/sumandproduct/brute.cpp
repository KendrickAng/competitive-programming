#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

#define var(x) {cout << #x << " = " << x << " " << endl;}

const ll MAX = 2 * 1e5 * 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // i to j inclusive
    int ans = 0;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            ll sum = 0;
            ll mult = 1;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
                if (mult * arr[k] > MAX) {
                    mult = -1;
                    break;
                }
                mult *= arr[k];
            }
            if (sum == mult) ans++;
        }
    }

    cout << ans << endl;
}
