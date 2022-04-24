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

const int MAX_S = 'z' - 'a' + 1;

int N, M;
vector<bool> one;
vector<vector<bool>> two;
vector<vector<vector<int>>> three;
vector<string> words;

void solve() {
    cin >> N >> M;
    three.assign(MAX_S, vector<vector<int>>(MAX_S, vector<int>(MAX_S, -1)));
    words.reserve(N);

    for (int i = 0; i < N; i++) {
        one.assign(MAX_S, false);
        two.assign(MAX_S, vector<bool>(MAX_S, false));
        string tmp; cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            for (int k = 0; k < MAX_S; k++) {
                for (int l = 0; l < MAX_S; l++) {
                    if (two[k][l] and (three[k][l][tmp[j]-'a'] == -1)) {
                        three[k][l][tmp[j]-'a'] = i;
                    }
                }
                if (one[k]) two[k][tmp[j]-'a'] = true;
            }
            one[tmp[j]-'a'] = true;
        }
        words.push_back(tmp);
    }

    // answer queries
    for (int i = 0; i < M; i++) {
        char a, b, c; cin >> a >> b >> c;
        int idx = three[a-'A'][b-'A'][c-'A'];
        if (idx != -1) {
            cout << words[idx] << '\n';
        } else {
            cout << "No valid word" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}