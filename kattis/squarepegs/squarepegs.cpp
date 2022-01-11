#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    double tmp;
    vector<double> plots, houses;
    for (int i = 0; i < n; i++) {
        cin >> tmp; plots.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp; houses.push_back(tmp);
    }
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        double tmp2 = sqrt(tmp*tmp + tmp*tmp) / 2.0;
        houses.push_back(tmp2);
    }
    sort(plots.begin(), plots.end());
    sort(houses.begin(), houses.end());

    int ans = 0, p = 0, h = 0;
    while ((p < plots.size()) && (h < houses.size())) {
        while ((p < plots.size()) && plots[p] <= houses[h]) p++;
        if (p >= plots.size()) break;
        ans++; p++; h++;
    }

    cout << ans << endl;
}