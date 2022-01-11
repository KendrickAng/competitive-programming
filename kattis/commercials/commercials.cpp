#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p; cin >> n >> p;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int profit; cin >> profit;
        arr[i] = profit-p;
    }

    // kadane's
    int sum = 0;
    int ans = 0;
    for (auto a: arr) {
        sum += a;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    cout << ans << endl;
}