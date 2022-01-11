#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// using ii = pair<int, int>;

long long getAnswer(vector<pair<int,int>> &arr, int k) {
    int letters = 0;
    int dist = arr[arr.size()-1].first * 2;
    for (int i = arr.size()-1; i >= 0; i--) {
        if (arr[i].second + letters <= k) {
            letters += arr[i].second;
            arr.pop_back();
        } else {
            int diff = k - letters;
            letters += diff;
            arr[i].second -= diff;
            break;
        }
    }
    return dist;
}

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> arrN, arrP;
    for (int i = 0; i < n; i++) {
        int x, t; cin >> x >> t;
        if (x > 0) arrP.push_back({x,t});
        else arrN.push_back({-x,t});
    }
    sort(arrP.begin(), arrP.end());
    sort(arrN.begin(), arrN.end());

    long long ans = 0;

    while (!arrP.empty()) {
        ans += getAnswer(arrP, k);
    }
    while (!arrN.empty()) {
        ans += getAnswer(arrN, k);
    }
    cout << ans << endl;
}
