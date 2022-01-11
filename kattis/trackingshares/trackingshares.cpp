#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
unordered_set<int> seen;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c; cin >> c;
    arr.assign(c, vector<int>(366, 0));

    // read in initial input
    int maxDay = -1;
    for (int companyId = 0; companyId < c; companyId++) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            int shares, day; cin >> shares >> day;
            arr[companyId][day] = shares;

            maxDay = max(maxDay, day);
            seen.insert(day);
        }
    }

    // front-fill shares
    for (int companyId = 0; companyId < c; companyId++) {
        int curr = 0;
        for (int day = 1; day <= maxDay; day++) {
            if (arr[companyId][day] != 0) {
                curr = arr[companyId][day];
            } else {
                arr[companyId][day] = curr;
            }
        }
    }

    // calculate total shares per day
    for (int day = 1; day <= maxDay; day++) {
        if (!seen.count(day)) continue;
        
        long sum = 0;
        for (int companyId = 0; companyId < c; companyId++) {
            sum += arr[companyId][day];
        }
        if (sum != 0) cout << sum << " ";
    }
    cout << endl;
}