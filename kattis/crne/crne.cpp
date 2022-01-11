#include <bits/stdc++.h>

using namespace std;

int main() {
    // https://oeis.org/A002620/list
    int n; cin >> n;
    n += 2;
    cout << fixed << (long long) floor((double) n * n / 4) << endl;
}