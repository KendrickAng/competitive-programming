#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n; cin >> n;
    for (long long i = 1; i < 1e9; i++) {
        if (i * (2*i+1) * (2*i-1) / 3 > n) {
            cout << i-1 << endl;
            break;
        }
    }
}