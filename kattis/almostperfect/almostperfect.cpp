#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int limit = sqrt(n);
    long sum = 0;
    for (int i = 1; i <= limit; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / i;
            sum += a;
            if (b != a && b <= n-1) sum += b;
        }
    }
    // cout << "sum is " << sum << endl;
    cout << n << " ";
    if (sum == n) cout << "perfect" << endl;
    else if (abs(sum-n) <= 2) cout << "almost perfect" << endl;
    else cout << "not perfect" << endl;
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
}