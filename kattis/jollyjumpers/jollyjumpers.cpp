#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n;
        ss >> n;
        vector<int> arr;
        vector<bool> check(300001, false);

        for (int i = 0; i < n; i++) {
            int tmp; ss >> tmp;
            arr.push_back(tmp);
        }

        int num;
        for (int i = 1; i < arr.size(); i++) {
            num = abs(arr[i] - arr[i-1]);
            check[num] = true;
        }

        bool jolly = true;
        for (int i = 1; i <= n-1; i++) {
            if (!check[i]) {
                jolly = false;
                break;
            }
        }

        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not Jolly" << endl;
        }
    }
}