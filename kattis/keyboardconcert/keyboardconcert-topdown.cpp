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

int N, M;
const int MAX_N = 1005;
const int MAX_M = 1005;
const int MAX_K = 1005;
int memo[MAX_M][MAX_N];
int tune[MAX_K];
vector<vector<int>> noteToInstr;

int dp(int pos, int instr) {
    if ((pos >= M-1) or (instr >= N)) return 0;
    int &ans = memo[pos][instr];
    if (ans == -1) {
        int tmp = 1e9;
        int nextNote = tune[pos+1];
        for (int i: noteToInstr[nextNote]) {
            if (i == instr) tmp = min(tmp, dp(pos+1, instr));
            else tmp = min(tmp, 1+dp(pos+1,i));
        }
        ans = tmp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    noteToInstr.assign(MAX_M, vector<int>());

    // read instruments
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int note; cin >> note;
            noteToInstr[note].push_back(i);
        }
    }

    // read tune
    for (int i = 0; i < M; i++) {
        cin >> tune[i];
    }

    memset(memo, -1, sizeof memo);
    int ans = INT_MAX;
    for (int i: noteToInstr[tune[0]]) {
        ans = min(ans, dp(0, i));
    }
    cout << ans << endl;
}