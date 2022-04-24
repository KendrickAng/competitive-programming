#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    regex e("([a-z])\\1+");
    cout << regex_replace(s, e, "$1") << endl;
}