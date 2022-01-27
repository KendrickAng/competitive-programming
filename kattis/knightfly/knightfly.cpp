#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int xStart, yStart, xEnd, yEnd; cin >> xStart >> yStart >> xEnd >> yEnd;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // compress
    vector<int> xCopy(x);
    vector<int> yCopy(y);
    sort(xCopy.begin(), xCopy.end());
    sort(yCopy.begin(), yCopy.end());
    unordered_map<int, int> xToxx;
    unordered_map<int, int> yToyy;
    int idx = 1;
    for (int x: xCopy) {
        if (xToxx.find(x) == xToxx.end()) xToxx[x] = idx++;
    }
    idx = 1;
    for (int y: yCopy) {
        if (yToyy.find(y) == yToyy.end()) yToyy[y] = idx++;
    }
    set<ii> spaces;
    for (int i = 0; i < n; i++) spaces.insert({ xToxx[x[i]], yToyy[y[i]] });

    // up/down, left/right
    vector<ii> offsetA = {{1,0},{1,0},{0,1},{0,1},{-1,0},{-1,0},{0,-1},{0,-1}};
    vector<ii> offsetB = {{0,-1},{0,1},{1,0},{-1,0},{0,1},{0,-1},{-1,0},{1,0}};

    // bfs
    queue<ii> q;
    int xxEnd = xToxx[xEnd];
    int yyEnd = yToyy[yEnd];
    int xx = xToxx[xStart];
    int yy = yToyy[yStart];
    // cout << "start: " << xx << " " << yy << endl;
    // cout << "end: " << xxEnd << " " << yyEnd << endl;

    set<ii> seen;
    seen.insert({ xx, yy });
    q.push({ xx, yy });

    int depth = 0;
    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            auto &[currX, currY] = q.front(); q.pop();
            
            if (currX == xxEnd && currY == yyEnd) {
                cout << depth << endl;
                return 0;
            }

            // iterate neighbours
            for (int i = 0; i < 8; i++) {
                auto &[ay, ax] = offsetA[i];
                int newX = currX + ax;
                int newY = currY + ay;
                ii nxt = { newX, newY };
                if (spaces.find(nxt) == spaces.end()) continue;

                newX = newX + ax;
                newY = newY + ay;
                nxt = { newX, newY };
                if (spaces.find(nxt) == spaces.end()) continue;

                auto &[by, bx] = offsetB[i];
                newX = newX + bx;
                newY = newY + by;
                nxt = { newX, newY };
                if (spaces.find(nxt) == spaces.end()) continue;

                if (newX == xxEnd && newY == yyEnd) {
                    cout << depth+1 << endl;
                    return 0;
                }

                if (seen.find(nxt) != seen.end()) continue; // already seen
                seen.insert(nxt);
                q.push(nxt);
            }
        }

        depth++;
    }

    cout << -1 << endl;
}