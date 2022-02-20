#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

#define var(x) {cout << #x << " = " << x << " " << endl;}

const ll MAX = 2 * 1e5 * 1e9;

void solve() {
    int n; cin >> n;
    
    // read input
    vector<ll> arr(n);
    vector<int> jump(n, -1); // jumps to next one
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n-1; i>= 0; i--)  {
        if (arr[i] == 1) jump[i] = max(i, jump[i+1]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll sum = arr[i];
        ll mult = arr[i];
        for (int j = i+1; j < n; j++) {
            if (arr[j] == 1) {
                int jumpLen = jump[j] - j + 1;
                if (sum + jumpLen >= mult && mult > sum) ans++;
                sum += jumpLen;
                j = jump[j];
            } else {
                sum += arr[j];
                if (mult > MAX / arr[j]) break;
                mult *= arr[j];
                if (sum == mult) ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    solve();
}
