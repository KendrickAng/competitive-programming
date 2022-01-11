#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> map{};
vector<vector<bool>> reached{};
int treasure = 0;

bool valid(int r, int c) {
    return r >= 0 && r < map.size() && c >= 0 && c < map[0].size();
}

void fill(int r, int c) {
    if (r < 0 || r >= map.size() || c < 0 || c >= map[0].size()) return;
    if (reached[r][c]) return;
    if (map[r][c] == '#') return;
    if (map[r][c] == 'T') return;

    char obj = map[r][c];
    reached[r][c] = true;
    if (obj == 'G') treasure++;
    if (valid(r-1, c) && map[r-1][c] == 'T') return;
    if (valid(r, c+1) && map[r][c+1] == 'T') return;
    if (valid(r+1, c) && map[r+1][c] == 'T') return;
    if (valid(r, c-1) && map[r][c-1] == 'T') return;

    fill(r-1, c);
    fill(r, c+1);
    fill(r+1, c);
    fill(r, c-1);
}

int main() {
    int w, h;
    std::cin >> w >> h;
    map.resize(h);
    reached.resize(h);
    pair<int, int> start;
    for (auto &a: map) a.resize(w);
    for (auto &a: reached) a.resize(w);
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            char cc; std::cin >> cc;
            map[r][c] = cc;
            if (cc == 'P') {
                start.first = r;
                start.second = c;
            }
        }
    }
    fill(start.first, start.second);
    std::cout << treasure << std::endl;
}