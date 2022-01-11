#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;

        vector<int> arr;
        for (int j = 0; j < 2*n; j++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());

        int back = 2*n-1;
        int front = 0;
        for (int j = 0; j < 2*n; j++) {
            if (j % 2 == 0) {
                cout << arr[back--] << " ";
            } else {
                cout << arr[front++] << " ";
            }
        }
        cout << endl;
    }
}