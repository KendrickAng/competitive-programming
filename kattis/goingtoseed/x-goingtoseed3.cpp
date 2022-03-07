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

const int MAX_LOOPS = 17;
int N;
bool isLeft;
bool isRight;

void query(int l1, int r1, int l2, int r2) {
    cout << "Q " + to_string(l1) + " " + to_string(r1) + " " + to_string(l2) + " " + to_string(r2) << endl;
}

void answer(int ans) {
    cout << "A " + to_string(ans) << endl;
}

void solve4(int left, int right) {
    query(left,left+2,left+1,right);
    cin >> isLeft >> isRight;
    if (isLeft and !isRight) {
        answer(left);
    } else if (isLeft and isRight) {
        answer(left+1);
    } else if (!isLeft and isRight) {
        answer(left+2);
    } else {
        answer(right);
    }
    exit(0);
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
    int right1 = 1 + 2*piece;
    int left2 = 1 + piece;
    int right2 = N - piece;
    int end = N;
    for (int i = 0; i < MAX_LOOPS; i++) {
        query(left1, right1, left2, right2);
        cin >> isLeft >> isRight;
        int left, right;
        if (isLeft and !isRight) {
            if (max(1,left2-1)-left1+1 == 4) solve4(left1, max(1,left2-1));
            if (max(1,left2-1)-left1+1 == 3) solve3(left1, max(1,left2-1));
            if (max(1,left2-1)-left1+1 == 2) solve2(left1, max(1,left2-1));
            if (max(1,left2-1)-left1+1 == 1) solve1(left1);
            left =  max(1, left1-1);
            right = left2;
        } else if (isLeft and isRight) {
            if (right1-left2+1 == 4) solve4(left2, right1);
            if (right1-left2+1 == 3) solve3(left2, right1);
            if (right1-left2+1 == 2) solve2(left2, right1);
            if (right1-left2+1 == 1) solve1(left2);
            left = max(1, left2-1);
            right = min(N, right1+1);
        } else if (!isLeft and isRight) {
            if (right2-min(N,right1+1)+1 == 4) solve4(min(N,right1+1), right2);
            if (right2-min(N,right1+1)+1 == 3) solve3(min(N,right1+1), right2);
            if (right2-min(N,right1+1)+1 == 3) solve2(min(N,right1+1), right2);
            if (right2-min(N,right1+1)+1 == 3) solve1(right2);
            left = right1;
            right = min(N, right2+1);
        } else {
            if (end-min(N,right2+1)+1 == 4) solve4(min(N,right2+1), end);
            if (end-min(N,right2+1)+1 == 3) solve3(min(N,right2+1), end);
            if (end-min(N,right2+1)+1 == 2) solve2(min(N,right2+1), end);
            if (end-min(N,right2+1)+1 == 1) solve1(end);
            left = right2;
            right = end;
        }
        // debug(left, right);
        piece = (right - left + 1) / 4;
        end = right;
        left1 = left;
        right1 = left + 2*piece;
        left2 = left + piece;
        right2 = end - piece;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}