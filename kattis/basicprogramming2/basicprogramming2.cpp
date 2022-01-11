#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, t; cin >> n >> t;
    vector<int> arr;
    unordered_map<int, int> counter;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
        counter[tmp]++;
    }

    if (t == 1) {
        bool ok = false;
        for (int num: arr) {
            if (counter[7777-num] != 0) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (t == 2) {
        bool unique = true;
        for (auto &[k,v]: counter) {
            if (v > 1) {
                unique = false;
            }
        }
        if (unique) cout << "Unique" << endl;
        else cout << "Contains Duplicate" << endl;
    }
    else if (t == 3) {
        int ans = -1;
        for (auto &[k,v]: counter) {
            if (v > n/2) {
                ans = k;
            }
        }
        cout << ans << endl;;
    }
    else if (t == 4) {
        sort(arr.begin(), arr.end());
        if (n % 2 != 0) {
            cout << arr[n/2] << endl;
        } else {
            cout << arr[n/2 - 1] << " " << arr[n/2] << endl;
        }
    }
    else if (t == 5) {
        sort(arr.begin(), arr.end());
        bool first = true;
        for (int num: arr) {
            if (num >= 100 && num <= 999) {
                if (first) {
                    first = false;
                } else {
                    cout << " ";
                }
                cout << num;
            }
        }
        cout << endl;
    }
}