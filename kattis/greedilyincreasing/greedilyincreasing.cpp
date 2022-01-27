#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int curr = -1;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (curr == -1 || tmp > curr) {
            nums.push_back(tmp);
            curr = tmp;
        }
    }

    cout << nums.size() << endl;
    for (int i: nums) cout << i << " ";
    cout << endl;
}