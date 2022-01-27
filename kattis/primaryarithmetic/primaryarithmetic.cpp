#include <bits/stdc++.h>

using namespace std;

int main() {
    long a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 and b == 0) break;

        int carry = 0;
        int carries = 0;
        while (a != 0 or b != 0) {
            int alast = a % 10;
            int blast = b % 10;
            int sum = alast + blast + carry;
            carry = 0;
            if (sum >= 10) {
                carry++;
                carries++;
            }
            a /= 10;
            b /= 10;
        }

        if (carries == 0) {
            cout << "No carry operation." << endl;
        } else if (carries == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carries << " carry operations." << endl;
        }
    }
}