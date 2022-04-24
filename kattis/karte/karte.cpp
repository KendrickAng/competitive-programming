#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using ii = pair<int, int>;

int missing(vector<bool> &arr) {
    int count = 0;
    for (bool b: arr) if (!b) count++;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string line; cin >> line;
    vector<bool> p(13, false);
    vector<bool> h(13, false);
    vector<bool> k(13, false);
    vector<bool> t(13, false);
    for (int i = 0; i < line.size(); i+=3) {
        char suit = line[i];
        int num = ((line[i+1]-'0') * 10) + (line[i+2]-'0');
        num--;
        if (suit == 'P') {
            if (p[num]) {
                cout << "GRESKA" << endl;
                return 0;
            }
            p[num] = true;
        } else if (suit == 'K') {
            if (k[num]) {
                cout << "GRESKA" << endl;
                return 0;
            }
            k[num] = true;
        } else if (suit == 'H') {
            if (h[num]) {
                cout << "GRESKA" << endl;
                return 0;
            }
            h[num] = true;
        } else if (suit == 'T') {
            if (t[num]) {
                cout << "GRESKA" << endl;
                return 0;
            }
            t[num] = true;
        }
    }

    cout << missing(p) << ' ' << missing(k) << ' ' << missing(h) << ' ' << missing(t) << endl;
}