#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    ll n; cin >> n;

    ll sofar = 1;
    for (ll i = 1; i <= n; i++) {
        sofar *= i;
        while (sofar % 10 == 0) {
            sofar /= 10;
        }
        sofar = sofar % 1000000000000; // 7 + 4 digits
    }

    while (sofar % 10 == 0) {
        sofar /= 10;
    }
    if (sofar < 1000) {
        cout << sofar << endl;
    } else {
        int c = sofar % 10; sofar /= 10;
        int b = sofar % 10; sofar /= 10;
        int a = sofar % 10; sofar /= 10;
        cout << a << b << c << endl;
    }
}