#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    for (ll n = 10000000; n >= 1; n--) {
        cout << "testing: " << n << endl;
        ll sofar = 1;
        ll sofar2 = 1;
        for (ll i = 1; i <= n; i++) {
            sofar *= i;
            sofar2 *= i;
            while (sofar % 10 == 0) {
                sofar /= 10;
            }
            while (sofar2 % 10 == 0) {
                sofar2 /= 10;
            }
            sofar = sofar % 1000000000000; // 7 + 4 digits
            sofar2 = sofar2 % 100000000000;
        }

        while (sofar % 10 == 0) {
            sofar /= 10;
        }
        while (sofar2 % 10 == 0) {
            sofar2 /= 10;
        }

        int c = sofar % 10; sofar /= 10;
        int b = sofar % 10; sofar /= 10;
        int a = sofar % 10; sofar /= 10;
        
        int cc = sofar2 % 10; sofar2 /= 10;
        int bb = sofar2 % 10; sofar2 /= 10;
        int aa = sofar2 % 10; sofar2 /= 10;

        if (a != aa || b != bb || c != cc) {
            cout << "UH OH: " << n << endl;
            cout << a << b << c << endl;
            cout << aa << bb << cc << endl;
            return 0;
        }
    }
    
}