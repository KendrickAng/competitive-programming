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

vector<int> arr;
vector<int> memo;
vector<int> p;
int lisEnd;
int globalMax;

void printLis(int i) {
    if (i == -1) return;
    printLis(p[i]);
    cout << arr[i] << ' ';
}

int LIS(int curr) {
    if (curr == 0) return 1;

    int &ans = memo[curr];
    if (ans != -1) return ans;

    ans = 1;
    for (int i = 0; i < curr; i++) {
        if ((arr[i] < arr[curr] && LIS(i)+1 > ans) ||  // can get a strictly longer subsequence
            (LIS(i)+1 == ans && p[curr] != -1 && arr[i] < arr[p[curr]])) { // can get a lexicographically smaller seq
            ans = LIS(i)+1;
            p[curr] = i;
            // update end of the longest subsequence
            if (ans > globalMax) {
                globalMax = ans;
                lisEnd = curr;
            }
        }
    }

    return ans;
}

void solve(int n) {
    arr.resize(n);
    memo.assign(n, -1);
    p.assign(n, -1);
    lisEnd = 0;
    globalMax = -1;

    // read input
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (is_sorted(arr.rbegin(), arr.rend())) {
        int min = arr[n-1];
        cout << "1 " << min << endl;
        return;
    }

    // LIS
    int ans = LIS(n-1);
    // debug(p);
    // debug(lisEnd);

    // print answer
    cout << ans << ' ';
    printLis(lisEnd);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        solve(n);
    }
}