#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int K, N;

struct Frac {
    ll numer;
    ll denom;
};

void solve() {
    cin >> K >> N;

    vector<Frac> fracs;
    // generate coprime numbers
    for (int i = 0; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (gcd(i, j) == 1) {
                fracs.push_back({ i, j });
            }
        }
    }

    // generate farey sequence
    sort(fracs.begin(), fracs.end(), [](Frac &a, Frac &b) {
        return ((double) a.numer / a.denom) < ((double) b.numer / b.denom);
    });

    // get common denominator
    ll denom = 1;
    for (int i = 1; i < fracs.size(); i++) {
        denom = lcm(denom, fracs[i].denom);
    }

    // count farey sum
    ll top = 0;
    ll bot = denom;
    for (int i = 0; i < fracs.size()-1; i++) {
        Frac &f1 = fracs[i];
        Frac &f2 = fracs[i+1];
        ll mult = denom / f2.denom;
        top += (f1.denom * mult);
    }

    ll a = top / gcd(top, bot);
    ll b = bot / gcd(top, bot);
    if (b == 1) {
        cout << K << " " << a << endl;
    } else {
        cout << K << " " << a << "/" << b << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}