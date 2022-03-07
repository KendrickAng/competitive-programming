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

int ID = 1;
int N;
vector<string> leftS;
vector<string> rightS;
vector<int> stuff;

pair<string,string> form() {
    vector<string> tmpLeft(N);
    vector<string> tmpRight(N);
    for (int i = 0; i < N; i++) {
        tmpLeft[i] = leftS[stuff[i]];
        tmpRight[i] = rightS[stuff[i]];
    }
    string leftStr;
    string rightStr;
    for (int i = 0; i < N; i++) {
        leftStr += tmpLeft[i];
        rightStr += tmpRight[i];
        if (leftStr.size() == rightStr.size() and leftStr == rightStr) return {leftStr, rightStr};
    }
    return {leftStr, rightStr};
}

void solve() {
    leftS.resize(N);
    rightS.resize(N);
    stuff.resize(N);

    // read input
    for (int i = 0; i < N; i++) {
        cin >> leftS[i] >> rightS[i];
        stuff[i] = i;
    }
    // sort(stuff.begin(), stuff.end());

    // permutate
    string sln;
    do {
        auto [lhs, rhs] = form();
        // debug(stuff);
        if (lhs == rhs and (sln.empty() or (lhs.size() < sln.size()) or (lhs < sln))) {
            sln = lhs;
        }
    } while (next_permutation(stuff.begin(), stuff.end()));
    
    cout << "Case " << ID++ << ": ";
    if (!sln.empty()) {
        cout << sln << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> N) {
        solve();
    }
}