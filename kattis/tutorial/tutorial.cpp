#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void one(ll m, ll n) {
    if (n >= 15) {
        cout << "TLE" << endl;
        return;
    }
    double sofar = 0;
    double limit = log(m);
    for (ll i = n; i >= 1; i--) {
        sofar += log(i);
    }

    if (sofar > limit) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void two(ll m, ll n) {
    if (n * log(2) > log(m)) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void three(ll m, ll n) {
    if (4 * log(n) > log(m)) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void four(ll m, ll n) {
    if (3 * log(n) > log(m)) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void five(ll m, ll n) {
    if (2 * log(n) > log(m)) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void six(ll m, ll n) {
    if (n * log2(n) > m) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

void seven(ll m, ll n) {
    if (n > m) {
        cout << "TLE" << endl;
    } else {
        cout << "AC" << endl;
    }
}

int main() {
    ll m, n, t; cin >> m >> n >> t;
    if (t == 1) {
        one(m, n);
    } else if (t == 2) {
        two(m, n);
    } else if (t == 3) {
        three(m, n);
    } else if (t == 4) {
        four(m, n);
    } else if (t == 5) {
        five(m, n);
    } else if (t == 6) {
        six(m, n);
    } else if (t == 7) {
        seven(m, n);
    }
}