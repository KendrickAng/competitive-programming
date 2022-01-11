#include <iostream>

using namespace std;
using ll = long long;

bool binarysearch(ll arr[], int size, ll val) {
    int low = 0;
    int high = size-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] == val) {
            return true;
        } else if (arr[mid] >= val) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, a, c, x0; cin >> n >> m >> a >> c >> x0;

    // fill array
    ll arr[n];
    for (int i = 0; i < n; i++) {
        // arr[i] = (((a%m * x0%m) %m) + c%m) % m;
        arr[i] = (a*x0 + c) % m;
        x0 = arr[i];
    }

    int ans = 0;
    for (auto a: arr) {
        if (binarysearch(arr, n, a)) {
            ans++;
        }
    }

    cout << ans << endl;
}
