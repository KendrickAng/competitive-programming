#include <vector>
#include <iostream>
#include <algorithm>

#define LSOne(S) ((S) & -(S))

using namespace std;

const int MAX_N = 11;

vector<vector<int>> dist(MAX_N, vector<int>(MAX_N));
vector<vector<int>> memo(MAX_N, vector<int>(1 << (MAX_N-1)));

void print(vector<int> &arr) {
    for (auto a: arr) cout << a << " ";
    cout << endl;
}

void print(vector<vector<int>> &arr) {
    for (auto a: arr) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
}

template <typename T>
void print(T &a) {
    cout << a << endl;
}

// returns the minimum distance needed to be covered
int dp(int u, int mask) {
    if (mask == 0) return dist[u][0]; // close the tour
    int &ans = memo[u][mask];
    if (ans != -1) return ans;
    ans = 1e9;
    int m = mask;
    // try all possible paths
    while (m) {
        int two_pow_v = LSOne(m);
        int v_idx = __builtin_ctz(two_pow_v) + 1;
        ans = min(ans, dist[u][v_idx] + dp(v_idx, mask^two_pow_v));
        m -= two_pow_v;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int xSize, ySize; cin >> xSize >> ySize; // these values aren't used
        int xStart, yStart; cin >> xStart >> yStart;
        int n; cin >> n;
        vector<int> x(n+1);
        vector<int> y(n+1);
        x[0] = xStart;
        y[0] = yStart;
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        // fill distance array
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int x1 = x[i]; int y1 = y[i];
                int x2 = x[j]; int y2 = y[j];
                dist[i][j] = dist[j][i] = (abs(x1-x2) + abs(y1-y2));
            }
        }
        for (auto &a: memo) fill(a.begin(), a.end(), -1); // reset memo table (don't need to reset distance table)
        cout << dp(0, (1 << n) - 1) << endl; 
    }
}