#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int,int>;

int main() {
    int n; cin >> n;
    vector<ii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    int lc = arr[0].first;
    int rc = arr[0].second;
    int ans = 0, i = 0;
    while (i < n) {
        while ((i < n) && (arr[i].first <= rc)) {
            lc = max(arr[i].first, lc);
            rc = min(arr[i].second, rc);
            i++;
        }
        ans++;
        if (i >= n) break;
        lc = arr[i].first;
        rc = arr[i].second;
    }
    cout << ans << endl;
}
