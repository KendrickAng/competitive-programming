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
        int maxInt = -100000;
        int minInt = 100000;
        int maxIdx, minIdx;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if (tmp > maxInt) {
                maxIdx = i;
                maxInt = tmp;
            }
            if (tmp < minInt) {
                minInt = tmp;
                minIdx = i;
            }
            arr.push_back(tmp);
        }

        int direct, twosides;
        direct = min(n- min(maxIdx, minIdx), max(maxIdx, minIdx) + 1);
        if (maxIdx > minIdx) swap(maxIdx, minIdx);
        twosides = maxIdx + 1 + n - minIdx;

        cout << min(direct, twosides) << endl;
    }
}
