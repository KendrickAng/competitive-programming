#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int num) {
    if (num < 10) return num;
    long long ans = 0;
    ans += 10 * (num/10);
    while (num > 0) {
        num /= 10;
        ans += num * 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;

        long long a = solve(l);
        long long b = solve(r);
        cout << b - a << endl;
    }
}