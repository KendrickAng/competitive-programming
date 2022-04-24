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
using ddd = tuple<double,double,double>;
using vi = vector<int>;

double dist(double a1, double b1, double a2, double b2) {
	return sqrt(pow(a1 - a2, 2) + pow(b1 - b2, 2));
}

bool intersect(ddd c1, ddd c2) {
	double a1, b1, r1, a2, b2, r2;
	tie(a1, b1, r1) = c1;
	tie(a2, b2, r2) = c2;
	double d = dist(a1, b1, a2, b2);
	return (abs(r1 - r2) <= d && d <= r1 + r2);
}

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }

    int maxSetSize() {
        int ans = -1;
        for (int s: setSize) ans = max(ans, s);
        return ans;
    }
};


void solve(int n) {
    vector<ddd> circles;
    circles.reserve(n);
    
    double a, b, r;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> r;
        circles.push_back({a, b, r});
    }

    if (n == 0) {
        cout << "The largest component contains 0 ring." << endl;
    } else if (n == 1) {
        cout << "The largest component contains 1 ring." << endl;
    } else {
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(circles[i], circles[j])) {
                    uf.unionSet(i, j);
                }		
            }
        }

        int result = uf.maxSetSize();
        if (result < 2) {
            cout << "The largest component contains " << result << " ring." << endl;
        } else {
            cout << "The largest component contains " << result << " rings." << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        int N; cin >> N;
        if (N == -1) break;
        solve(N);
    }
}