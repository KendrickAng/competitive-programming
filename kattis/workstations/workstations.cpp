#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> arrivals, departures;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arrivals.push_back(a);
        departures.push_back(a+b);
    }

    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    
}