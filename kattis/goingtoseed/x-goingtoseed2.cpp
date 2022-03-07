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

const int MAX_LOOPS = 16;
int N;
bool isLeft;
bool isRight;

void query(int l1, int r1, int l2, int r2) {
    cout << "Q " + to_string(l1) + " " + to_string(r1) + " " + to_string(l2) + " " + to_string(r2) << endl;
}

void answer(int ans) {
    cout << "A " + to_string(ans) << endl;
}

void solve3(int left, int right) {
    query(left, left, right, right);
    cin >> isLeft >> isRight;
    if (isLeft) {
        answer(left);
    } else if (isRight) {
        answer(right);
    } else {
        answer(left+1);
    }
    exit(0);
}

void solve2(int left, int right) {
    query(left,left,right,right);
    cin >> isLeft >> isRight;
    if (isLeft) {
        answer(left);
    } else {
        answer(right);
    }
    exit(0);
}

void solve1(int left) {
    answer(left);
    exit(0);
}

void solve() {
    cin >> N;
    if (N == 2) solve2(1, 2);
    if (N == 3) solve3(1, 3);

    int piece = N / 4;
    int left1 = 1;
    int right1 = 1+piece;
    int left2 = N-piece;
    int right2 = N;
    for (int i = 0; i < MAX_LOOPS; i++) {
        query(left1, right1, left2, right2);
        cin >> isLeft >> isRight;
        if (!isLeft and !isRight) {
            int left = right1;
            int right = left2;
            piece = (right - left + 1) / 4;
            // debug(left, right);
            left1 = left;
            right1 = left+piece;
            left2 = right-piece;
            right2 = right;
        } else {
            int left, right;
            if (isLeft) {
                left =  max(1, left1-1);
                right = min(N, right1+1);
            } else {
                left = max(1, left2-1);
                right = min(N, right2+1);
            }
            if (right-left+1 == 3) solve3(left, right);
            if (right-left+1 == 2) solve2(left, right);
            if (right-left+1 == 1) solve1(left);
            // debug(left, right);
            piece = (right - left + 1) / 4;
            left1 = left;
            right1 = left + piece;
            left2 = right - piece;
            right2 = right;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}