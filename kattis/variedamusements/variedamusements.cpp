#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

long A(int n, int a, int b, int c);
long B(int n, int a, int b, int c);
long C(int n, int a, int b, int c);

long A(int n, int a, int b, int c) {
    if (n == 0) return 1;
    long ans = (b * B(n-1, a, b, c)) + (c * C(n-1, a, b, c));
    return ans;
}

long B(int n, int a, int b, int c) {
    if (n == 0) return 1;
    long ans = (a * A(n-1, a, b, c)) + (c * C(n-1, a, b, c));
    return ans; 
}

long C(int n, int a, int b, int c) {
    if (n == 0) return 1;
    long ans = (a * A(n-1, a, b, c)) + (b * B(n-1, a, b, c));
    return ans; 
}

int main() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    long ans = a * A(n-1,a,b,c) + b * B(n-1,a,b,c) + c * C(n-1,a,b,c);
    cout << ans % MOD << endl;
}