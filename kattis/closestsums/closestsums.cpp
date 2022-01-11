#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int caseNum = 0;
    while (cin >> n) {
        caseNum++;

        // read in distinct integers
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());

        // calculate sums
        vector<int> sums;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                sums.push_back(arr[i]+arr[j]);
            }
        }

        // answer queries
        int m; cin >> m;
        cout << "Case " << caseNum << ":" << endl;
        for (int i = 0; i < m; i++) {
            int query; cin >> query;
            int ans = sums[0];
            int distance = abs(sums[0]-query);
            for (auto &a: sums) {
                int newDistance = abs(a-query);
                if (newDistance < distance) {
                    ans = a;
                    distance = newDistance;
                }
            }
            cout << "Closest sum to " << query << " is " << ans << "." << endl;
        }
    }
}