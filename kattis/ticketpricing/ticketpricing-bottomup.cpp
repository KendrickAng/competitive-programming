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

int N, W;
vector<int> bestIdx;
const int INF = 1 << 30;
const int MAX_W = 53;
const int MAX_N = 301;
const int MAX_K = 101;

// input data structutres
int options[MAX_W];
int ticPrice[MAX_W][MAX_K];
int ticAmt[MAX_W][MAX_K];

// dp data structures
int memo[MAX_W][MAX_N]; // how much can be earned at the end of week W with N tickets left
int smallest[MAX_W][MAX_N]; // smallest ticket price at end of week W with N tickets left that gives optimal sln

void solve() {
    int N, W; cin >> N >> W;
    for (int i = 0; i <= W; i++) {
        cin >> options[i];
        int k = options[i];
        for (int j = 0; j < k; j++) cin >> ticPrice[i][j];
        for (int j = 0; j < k; j++) cin >> ticAmt[i][j];
    }

    memset(memo, -1, sizeof memo);

    // base case - calculate all possible sales of first week
    for (int i = 0; i < MAX_N; i++) smallest[0][i] = INF;
    for (int tIdx = 0; tIdx < options[0]; tIdx++) {
        int sold = min(ticAmt[0][tIdx], N);
        int price = ticPrice[0][tIdx];
        int earned = sold * price;
        int left = N - sold;
        if (memo[0][left] < earned or (memo[0][left] == earned and price < smallest[0][left])) {
            memo[0][left] = earned;
            smallest[0][left] = price;
        }
    }

    // inductive steps
    for (int wk = 1; wk <= W; wk++) {
        for (int tix = 0; tix <= N; tix++) {
            // can't form outgoing edge, skip
            if (memo[wk-1][tix] == -1) continue;

            for (int tIdx = 0; tIdx < options[wk]; tIdx++) {
                int sold = min(ticAmt[wk][tIdx], tix);
                int price = ticPrice[wk][tIdx];
                int earned = sold * price;
                int left = tix - sold;
                int candidate = memo[wk-1][tix] + earned;
                if (memo[wk][left] < candidate) {
                    memo[wk][left] = candidate;
                    smallest[wk][left] = smallest[wk-1][tix];
                } else if (memo[wk][left] == candidate) {
                    memo[wk][left] = candidate;
                    smallest[wk][left] = min(smallest[wk][left], smallest[wk-1][tix]);   
                }
            }
        }
    }

    int maxEarnings = 0;
    int bestChoice = 0;
    for (int tix = 0; tix <= N; tix++) {
        if (maxEarnings < memo[W][tix]) { // found first sln
            maxEarnings = memo[W][tix];
            bestChoice = smallest[W][tix];
        } else if (maxEarnings == memo[W][tix]) { // can improve sln?
            maxEarnings = memo[W][tix];
            bestChoice = min(bestChoice, smallest[W][tix]);
        }
    }

    cout << maxEarnings << endl;
    cout << bestChoice << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}