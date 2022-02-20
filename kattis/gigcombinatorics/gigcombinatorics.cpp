#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

const int MOD = 1e9 + 7;

int n;
vector<int> songs;
vector<int> memo;
vector<int> ones;

// counts the number of subsequences up to i of form 1 2...
int dp(int i) {
    if (i == 0) return 0;

    int &ans = memo[i];
    if (ans != -1) return ans;

    if (songs[i] == 2) {
        ans = 2 * dp(i-1) + ones[i];
    } else {
        ans = dp(i-1);
    }

    return ans % MOD;
}

void solve() {
    cin >> n;

    memo.assign(n, -1);
    ones.assign(n, 0);

    // read in input
    songs.resize(n);
    for (int i = 0; i < n; i++) cin >> songs[i];

    // edge cases
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    // fill up ones array
    ones[0] = songs[0] == 1 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        ones[i] = ones[i-1];
        if (songs[i] == 1) ones[i]++;
    }

    // answer queries
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (songs[i] == 3) {
            ans += dp(i);
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
