#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sizes, colors;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    sizes.resize(n);
    colors.resize(m);
    for (int i = 0; i < n; i++) cin >> sizes[i];
    for (int i = 0; i < m; i++) cin >> colors[i];
    sort(sizes.begin(), sizes.end());

    long long ans = 0;
    for (auto a: colors) {
        ans += *lower_bound(sizes.begin(), sizes.end(), a) - a;
    }
    cout << ans << endl;
}