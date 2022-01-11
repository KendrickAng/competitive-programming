#include <vector>
#include <iostream>
#include <algorithm>

#define LSOne(S) ((S) & -(S))

using namespace std;

const int MAX_N = 11;

vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, -1));
// vector<vector<int>> memo(MAX_N, vector<int>(1 << (MAX_N-1)));

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

void solve() {
    int xSize, ySize; cin >> xSize >> ySize; // these two values are not used
    int xStart, yStart; cin >> xStart >> yStart;
    int n; cin >> n;
    vector<int> x(n+1);
    vector<int> y(n+1);
    x[0] = xStart;
    y[0] = yStart;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    // create the distance array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            // manhattan distance
            int x1 = x[i]; int y1 = y[i];
            int x2 = x[j]; int y2 = y[j];
            int manhattan = abs(x1-x2) + abs(y1-y2);
            dist[i][j] = manhattan;
            dist[j][i] = manhattan;
        }
    }

    // print(dist);

    // start and end at i=0, so we leave it out
    vector<int> order;
    for (int i = 1; i <= n; i++) order.push_back(i);

    int minDist = 1e9;
    do {
        // brute force solution
        // print(order);
        int currDist = dist[0][order.front()];
        for (int i = 1; i < order.size(); i++) {
            currDist += dist[order[i]][order[i-1]];
        }
        currDist += dist[order.back()][0];
        // print(currDist);
        minDist = min(minDist, currDist);
    } while (next_permutation(order.begin(), order.end()));
    
    cout << minDist << endl;
}

int main() {
    int n; cin >> n;
    while (n--) {
        solve();
    }
}