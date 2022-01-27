#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 != 0) {
                int num = (s[i] - '0') * 2;
                if (num > 9) num = (num / 10) + (num % 10);
                sum += num;
            } else {
                sum += s[i] - '0';
            }
        }
        if (sum % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }
}