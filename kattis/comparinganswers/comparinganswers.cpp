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

vector<vector<int>> A;
vector<vector<int>> B;
int checks = 4;
int domain = 2;

vector<int> mult(const vector<vector<int>> &mat, const vector<int> &vec) {
    vector<int> ret(vec.size(), 0);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            ret[i] += mat[i][j] * vec[j];
        }
    }
    return ret;
}

void solve(int n) {
    A.assign(n, vector<int>(n));
    B.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> verifies(checks, vector<int>(n));
    for (int i = 0; i < checks; i++) {
        for (int j = 0; j < n; j++) {
            verifies[i][j] = rand() % domain;
        }
    }
    
    // Frievald's O(n^2) randomised algorithm: better than Strassen's O(n^2.807) algorithm
    // Solves the problem: given three n x n matrices A, B, C, verify if AxB = C
    // 1. Generate a nx1 random 0/1 vector r, this is a "witness vector" 
    // 2. check if AxBxr != Cxr, if so output "NO", otherwise "YES"
    // there's a (1 - 1/domain) chance of finding a witness per check
    // probability of finding witness = 1 - (checks * (1-1/domain))
    for (int i = 0; i < checks; i++) {
        vector<int> a = mult(A, mult(A, verifies[i]));
        vector<int> b = mult(B, verifies[i]);
        // debug(a, b);
        if (a != b) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
}