#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector<int> xOff = {-1, 1, 0, 0};
vector<int> yOff = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int p1; cin >> p1;
        if (p1 == 0) break;

        queue<iii> q;
        vector<vector<int>> map(2001, vector<int>(2001, false));

        for (int i = 0; i < p1; i++) {
            int a, b; cin >> a >> b;
            q.push({a, b, 0});
            map[a][b] = 1;
        }

        int p2; cin >> p2;
        for (int i = 0; i < p2; i++) {
            int a, b; cin >> a >> b;
            map[a][b] = 2;
        }

        // bfs
        bool done = false;
        while (!q.empty()) {
            auto [x, y, dist] = q.front(); q.pop();

            // iterate neighborus
            for (int i = 0; i < 4; i++) {
                int xx = x + xOff[i];
                int yy = y + yOff[i];
                if (xx < 0 || xx > 2000 || yy < 0 || yy > 2000) continue; // out of bounds
                if (map[xx][yy] == 1) continue;

                if (map[xx][yy] == 2) {
                    cout << dist+1 << endl;
                    done = true;
                    break;
                }

                map[xx][yy] = 1;
                q.push({xx,yy,dist+1});
            }

            if (done) break;
        }
    }
}