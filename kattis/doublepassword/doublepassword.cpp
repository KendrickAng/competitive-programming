#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b; cin >> a >> b;
    int ans = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) ans <<= 1;
    }
    cout << ans << endl;
}