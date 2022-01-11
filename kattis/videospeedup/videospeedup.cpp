#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, p, k; cin >> n >> p >> k;
    vector<int> timestamps;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        timestamps.push_back(tmp);
    }
    
    int multiplier = 0;
    int prev = 0;
    double ans = 0;
    for (int ts: timestamps) {
        ans += (ts - prev) * ((100.0+(multiplier*p))/100);
        prev = ts;
        multiplier++;
    }
    ans += (k - prev) * ((100.0+(multiplier*p))/100);

    cout << fixed << setprecision(10) << ans << endl;
}