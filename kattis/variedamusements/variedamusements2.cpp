#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

long A(int n, int a, int b, int c) {
    long aLast = 1;
    long bLast = 1;
    long cLast = 1;

    long aCurr, bCurr, cCurr;
    for (int i = 0; i < n-1; i++) {
        aCurr = (((b%MOD) * (bLast%MOD))%MOD) + (((c%MOD) * (cLast%MOD)%MOD));
        bCurr = (((a%MOD) * (aLast%MOD))%MOD) + (((c%MOD) * (cLast%MOD)%MOD));
        cCurr = (((a%MOD) * (aLast%MOD))%MOD) + (((b%MOD) * (bLast%MOD)%MOD));

        aLast = aCurr;
        bLast = bCurr;
        cLast = cCurr;
    }

    return ((a%MOD) * (aLast%MOD))%MOD + ((b%MOD) * (bLast%MOD))%MOD + ((c%MOD) * (cLast%MOD))%MOD;
}

int main() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    long ans = A(n,a,b,c);
    cout << ans % MOD << endl;
}