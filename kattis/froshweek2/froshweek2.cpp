#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tasks, intervals;

int main() {
    int n, m, tmp; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tasks.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        intervals.push_back(tmp);
    }
    sort(tasks.begin(), tasks.end());
    sort(intervals.begin(), intervals.end());
    int ans = 0, nn = 0, mm = 0;
    while ((nn < n) && (mm < m)) {
        // find first interval >= task
        while ((mm < m) && intervals[mm] < tasks[nn]) mm++;
        if (mm >= m) break;
        ans++; nn++; mm++;
    }
    cout << ans << endl;
}