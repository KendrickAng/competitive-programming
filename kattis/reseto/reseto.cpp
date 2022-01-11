#include <bits/stdc++.h>

using namespace std;

bitset<100010> bs;

int main() {
    int n, k; cin >> n >> k;

    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (bs[i]) {
            for (int j = i; j <= n; j+=i) {
                if (bs[j]) {
                    bs[j] = 0;
                    k--;
                    if (k == 0) {
                        cout << j << endl;
                        return 0;
                    }
                }
            }
        }
    }
}