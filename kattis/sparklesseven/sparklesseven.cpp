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

vector<vector<int>> grid;
vector<vector<int>> ops;

vector<int> count(int one, int two, int three, int four, int five, int six, int seven, int row) {
    vector<int> ret;
    if (one == row) ret.push_back(0);
    if (two == row) ret.push_back(1);
    if (three == row) ret.push_back(2);
    if (four == row) ret.push_back(3);
    if (five == row) ret.push_back(4);
    if (six == row) ret.push_back(5);
    if (seven == row) ret.push_back(6);
    return ret;
}

void solve() {
    grid.assign(7, vector<int>(7));
    ops.clear();

    // read input
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> grid[i][j];
        }
    }

    // solve
    int minOps = INT_MAX;
    bool hasAns = false;
    for (int one = 0; one < 7; one++) { // row
        for (int two = 0; two < 7; two++) {
            for (int three = 0; three < 7; three++) {
                for (int four = 0; four < 7; four++) {
                    for (int five = 0; five < 7; five++) {
                        for (int six = 0; six < 7; six++) {
                            for (int seven = 0; seven < 7; seven++) {
                                int sum = grid[one][0]+grid[two][1]+grid[three][2]+grid[four][3]+grid[five][4]+grid[six][5]+grid[seven][6];
                                if (sum == 7) {
                                    // count operations
                                    vector<int> ts = count(one,two,three,four,five,six,seven,0);
                                    vector<int> aj = count(one,two,three,four,five,six,seven,1);
                                    vector<int> ra = count(one,two,three,four,five,six,seven,2);
                                    vector<int> pp = count(one,two,three,four,five,six,seven,3);
                                    vector<int> fs = count(one,two,three,four,five,six,seven,4);
                                    vector<int> rd = count(one,two,three,four,five,six,seven,5);
                                    vector<int> sp = count(one,two,three,four,five,six,seven,6);
                                    int numOps = max(ts.size(),max(aj.size(),max(ra.size(),max(pp.size(),max(fs.size(),max(rd.size(),sp.size()))))));
                                    if (numOps < minOps) {
                                        // generate answer
                                        minOps = numOps;
                                        hasAns = true;
                                        ops.clear(); // op idx to people sent
                                        ops.push_back(ts);
                                        ops.push_back(aj);
                                        ops.push_back(ra);
                                        ops.push_back(pp);
                                        ops.push_back(fs);
                                        ops.push_back(rd);
                                        ops.push_back(sp);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // debug(ops);

    if (hasAns) {
        cout << minOps << endl;

        // print ops
        vector<string> name = {
            "Twilight Sparkle",
            "Applejack",
            "Rarity",
            "Pinkie Pie",
            "Fluttershy",
            "Rainbow Dash",
            "Spike",
        };
        for (int c = 0; c < 7; c++) {
            bool hasStuff = false;
            vector<string> toPrint;
            for (int r = 0; r < 7; r++) {
                if (c < ops[r].size()) {
                    hasStuff = true;
                    toPrint.push_back(name[r] + " " + to_string(ops[r][c]+1));
                }
            }

            if (!hasStuff) break;
            cout << toPrint.size() << endl;
            for (string &s: toPrint) cout << s << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}