#include <bits/stdc++.h>

using namespace std;

int main() {
    string c, k; cin >> c >> k;
    for (int i = 0; i < c.size(); i++) {
        char cc;
        if (i % 2 != 0) {
            cc = c[i] + (k[i] - 'A');
            if (cc > 'Z') cc -= 26;
        } else {
            cc = c[i] - (k[i] - 'A');
            if (cc < 'A') cc += 26;
        }
        cout << cc;
    }
}