#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod(ll a, ll m) {
    return ((a % m) + m) % m;
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        tie(a, b) = tuple(b, a%b);
        tie(x, xx) = tuple(xx, x-q*xx);
        tie(y, yy) = tuple(yy, y-q*yy);
    }
    return a; // returns gcd(a, b)
}

int main() {
    ll p1 = 0, p2 = 0, pt = 0, t = 0;
    string s; 
    // Had to read in like this because of weird rounding error
    getline(cin, s, '.'); pt += 100*stoi(s);
    cin >> t; pt += t;
    getline(cin, s, '.'); p1 += 100*stoi(s);
    cin >> t; p1 += t;
    getline(cin, s, '.'); p2 += 100*stoi(s);
    cin >> t; p2 += t;

    ll x, y;
    ll d = extEuclid(p1, p2, x, y);

    // the equation ax + by = c has no integral slns if d | c is not true, d = gcd(a, b)
    if (pt % d != 0) {
        cout << "none" << endl;
        return 0;
    }

    ll x0 = x * (pt / d);
    ll xMult = p2 / d;
    ll yy = y * (pt / d);
    ll yMult = p1 / d;
    
    ll lowerBound = ceil((double) -x0 / xMult); // xx + xMult(n) >= 0
    ll upperBound = floor((double) yy / yMult);

    if (lowerBound > upperBound) {
        cout << "none" << endl;
        return 0;
    }

    for (ll i = lowerBound; i <= upperBound; i++) {
        cout << x0 + xMult*i << " " << yy - yMult*i << endl;
    }
}