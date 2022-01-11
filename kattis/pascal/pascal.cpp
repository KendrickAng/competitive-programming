#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    for (int i = 2; i <= (int) sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;

    // prime number or special case 1
    if (n == 1 || isPrime(n)) {
        cout << n-1 << endl;
        return 0;
    }

    // find smallest prime factor
    int factor = -1;
    for (int i = 2; i <= (int) sqrt(n); i++) {
        if (n % i == 0) {
            factor = i;
            break;
        }
    }

    cout << n - (n/factor) << endl;
}