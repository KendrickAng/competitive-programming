#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        ll ans; ss >> ans;
        ll tmp;
        while (ss >> tmp) {
            ans = lcm(ans, tmp);
        }
        cout << ans << endl;
    }
}