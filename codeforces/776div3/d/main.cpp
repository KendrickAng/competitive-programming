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
using iii = tuple<int,int,int>;

void leftShift(vector<int> &arr, int times) {
    vector<int> tmp;
    for (int i = times; i < arr.size(); i++) {
        tmp.push_back(arr[i]);
    }
    for (int i = 0; i < times; i++) {
        tmp.push_back(arr[i]);
    }
    for (int i = 0; i < tmp.size(); i++) {
        arr[i] = tmp[i];
    }
}

void solve() {
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> ans;
    for (int i = N; i >= 1; i--) {
        // find the element
        int idx = find(arr.begin(), arr.end(), i) - arr.begin();
        // cout << i << " is at " << idx << endl;
        // debug(arr);
        leftShift(arr, idx+1);
        // cout << "after" << endl;
        // debug(arr);    
        arr.pop_back();
        ans.push_back((idx+1) % i);
    }

    reverse(ans.begin(), ans.end());
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // vector<int> test = {1,2,3,4,5};
    // debug(test);
    // leftShift(test, 3);
    // debug(test);
    int t; cin >> t;
    while (t--) solve();
}