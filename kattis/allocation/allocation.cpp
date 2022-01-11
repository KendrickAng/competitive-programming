#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n, b; cin >> n >> b;
        vector<int> houses;
        for (int i = 0; i < n; i++) {
            int ai; cin >> ai;
            houses.push_back(ai);
        }
        sort(houses.begin(), houses.end());

        int bought = 0;
        long total = 0;
        for (auto &cost: houses) {
            if (total + cost > b) {
                break;
            }
            bought += 1;
            total += cost;
        }

        cout << "Case #" << i+1 << ": " << bought << endl;
    }
}
