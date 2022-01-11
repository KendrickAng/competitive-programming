#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
            sum += tmp;
        }
        
        if (sum % n != 0) {
            cout << -1 << endl;
        }
        else {
            int ans = 0;
            int limit = sum / n;
            for (int num: arr) {
                if (num > limit) ans++;
            }
            cout << ans << endl;
        }
    }
}