#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int l, d, n; cin >> l >> d >> n;
    vector<int> arr(n+2);
    arr[0] = 6-d;
    arr[arr.size()-1] = l-6+d;
    for (int i = 1; i < n+1; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int ans = 0;
    int left = 0 + 6; // inclusive
    int right = l - 6;

    if (left > right) {
        ans = 0;
    } else {
        int prev = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int curr = arr[i];
            ans += ((curr-prev)/d)-1;
            prev = curr;
        }
    }

    cout << ans << endl;
}