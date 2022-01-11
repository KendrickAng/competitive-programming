#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    while (cin >> n) {
        ll digits = 1;
        ll ones = 1;
        while (ones % n != 0) {
            ones = ones * 10 + 1;
            digits++;
            ones = ones % n;
        }
        cout << digits << endl;
    }
}