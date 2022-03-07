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

const int INF = 1e9 + 10;

struct Microbe {
    int idx;
    int x;
    int speed;
    int pid = -1;
};

int N;
unordered_map<int,int> idxToPart;
map<int,int> tracker;
vector<Microbe> microbes;

void solve() {
    cin >> N;
    idxToPart.clear();
    microbes.resize(N);

    // read input
    for (int i = 0; i < N; i++) {
        int x, speed; cin >> x >> speed;
        microbes[i] = {i, x, speed, -1};
    }

    sort(microbes.begin(), microbes.end(), [](const Microbe& m1, const Microbe& m2) {
        if (m1.x != m2.x) {
            return m1.x < m2.x;
        } else {
            return m1.speed < m2.speed;
        }
    });

    // greedy
    int partition = 0;
    tracker.insert({INF, -1});
    for (int i = 0; i < N; i++) {
        int speed = microbes[i].speed;
        auto it = tracker.upper_bound(speed);        
        if (it == tracker.begin()) {
            // start a new chain
            microbes[i].pid = ++partition;
            tracker[speed] = partition;
        } else {
            // expand the chain
            it--;
            int prevPartition = it->second;
            microbes[i].pid = prevPartition;
            tracker.erase(it);
            tracker[speed] = prevPartition;
        }
    }

    sort(microbes.begin(), microbes.end(), [](const Microbe &m1, const Microbe& m2) {
        return m1.idx < m2.idx;
    });

    for (const Microbe& m: microbes) {
        cout << m.pid << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}