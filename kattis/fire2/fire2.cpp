#include <bits/stdc++.h>

using namespace std;

enum Status {
    WALL,
    PERSON,
    FREE,
    ON_FIRE,
    NO_FIRE,
};

string translate(Status &status) {
    if (status == WALL) return "WALL";
    if (status == PERSON) return "PERSON";
    if (status == FREE) return "FREE";
    if (status == ON_FIRE) return "ON_FIRE";
    if (status == NO_FIRE) return "NO_FIRE";
}

int rows;
int cols;
vector<vector<bool>> seen;
vector<vector<Status>> fire;

bool valid(int r, int c) {
    return r >= 0 and r < rows and c >= 0 and c < cols;
}

void solve() {
    cin >> cols >> rows;
    fire.assign(rows, vector<Status>(cols, NO_FIRE));
    seen.assign(rows, vector<bool>(cols, false));

    // row, col, seconds, status
    queue<tuple<int,int,int,Status>> q;
    vector<tuple<int,int>> fires;

    // read in grid
    char chr;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> chr;
            if (chr == '#') {
                fire[r][c] = WALL;
            } else if (chr == '*') {
                fire[r][c] = ON_FIRE;
                fires.push_back({r,c});
            } else if (chr == '@') {
                fire[r][c] = NO_FIRE;
                q.push({r,c,0,PERSON});
                seen[r][c] = true;
            } else if (chr == '.') {
                fire[r][c] = NO_FIRE;
            }
        }
    }

    for (auto [r,c]: fires) {
        q.push({r,c,0,ON_FIRE});
    }

    // bfs
    int ans = -1;
    while (!q.empty()) {
        // de-queue next thing
        auto [r, c, time, status] = q.front(); q.pop();
        //cout << r << " " << c << " " << time << " " << translate(status) << endl;

        // if person + already on fire, ignore
        if (status == PERSON && fire[r][c] == ON_FIRE) continue;

        // if fire, mark current as on fire, NSEW as catching fire
        if (status == ON_FIRE) {
            fire[r][c] = ON_FIRE;
            if (valid(r+1, c) && fire[r+1][c] == NO_FIRE) {
                fire[r+1][c] = ON_FIRE;
                q.push({r+1, c, time+1, ON_FIRE});
            }
            if (valid(r-1, c) && fire[r-1][c] == NO_FIRE) {
                fire[r-1][c] = ON_FIRE;
                q.push({r-1, c, time+1, ON_FIRE});
            }
            if (valid(r, c+1) && fire[r][c+1] == NO_FIRE) {
                fire[r][c+1] = ON_FIRE;
                q.push({r, c+1, time+1, ON_FIRE});
            }
            if (valid(r, c-1) && fire[r][c-1] == NO_FIRE) {
                fire[r][c-1] = ON_FIRE;
                q.push({r, c-1, time+1, ON_FIRE});
            }
        }

        // if person, try to go NSEW if not on fire/catching fire, check for success
        if (status == PERSON) {
            if (r+1 >= rows || r-1 < 0 || c+1 >= cols || c-1 < 0) {
                ans = time + 1;
                break;
            }
            if (valid(r+1, c) && fire[r+1][c] == NO_FIRE && !seen[r+1][c]) {
                seen[r+1][c] = true;
                q.push({r+1, c, time+1, PERSON});
            }
            if (valid(r-1, c) && fire[r-1][c] == NO_FIRE && !seen[r-1][c]) {
                seen[r-1][c] = true;
                q.push({r-1, c, time+1, PERSON});
            }
            if (valid(r, c+1) && fire[r][c+1] == NO_FIRE && !seen[r][c+1]) {
                seen[r][c+1] = true;
                q.push({r, c+1, time+1, PERSON});
            }
            if (valid(r, c-1) && fire[r][c-1] == NO_FIRE && !seen[r][c-1]) {
                seen[r][c-1] = true;
                q.push({r, c-1, time+1, PERSON});
            }
        }
    }

    if (ans == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}