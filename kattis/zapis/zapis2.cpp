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

const int MOD = 100000;
const vector<char> stuff = {'(', '[', '{', '}', ']', ')'};

int n;

bool valid(string &s) {
    stack<char> stk;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' and !stk.empty() and stk.top() == '(' ||
                    c == ']' and !stk.empty() and stk.top() == '[' ||
                    c == '}' and !stk.empty() and stk.top() == '{') {
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}

int dp(int i, string &s) {
    if (i >= n and valid(s)) return 1;
    if (i >= n) return 0; 

    int ans = 0;
    if (s[i] == '?') {
        for (char ch: stuff) {
            s[i] = ch;
            ans += dp(i+1, s);
            s[i] = '?';
        }
    } else {
        ans += dp(i+1, s); // do nothing
    }

    return ans;
}

void solve() {
    cin >> n;

    // read input string
    string s;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s.push_back(c);
    }

    int ans = dp(0, s);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
