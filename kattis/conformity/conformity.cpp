#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unordered_set<int>> choices{};
    for (int i = 0; i < n; i++) {
        unordered_set<int> choice{};
        for (int j = 0; j < 5; j++) {
            int tmp; cin >> tmp;
            choice.insert(tmp);
        }
        choices.push_back(choice);
    }
    int ans = -1;
    for (int i = 0; i < choices.size(); i++) {
        int ans2 = 1;
        for (int j = i+1; j < choices.size(); j++) {
            if (choices[i] == choices[j]) {
                ans2 ++;
            }
        }
        ans = max(ans, ans2);
    }
    if (ans == 1) {
        ans = n;
    }
    cout << ans << endl;
}
