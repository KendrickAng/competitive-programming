#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// area, isCCW
pair<double, bool> shoelace(vector<pair<int,int>> pts) {
    auto first = pts[0];
    pts.push_back(first);
    double area = 0;
    for (int i = 0; i < pts.size()-1; i++) {
        area += pts[i].first * pts[i+1].second;
        area -= pts[i+1].first * pts[i].second;
    }
    area *= 0.5;
    // area positive = counterclockwise, negative = clockwise
    if (area > 0) {
        return { abs(area), true };
    }
    return { abs(area), false };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(1);

    int n; cin >> n;
    while (n != 0) {
        vector<pair<int, int>> pts;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            pts.push_back({x,y});
        }
        auto [area, isCCW] = shoelace(pts);
        if (isCCW) {
            cout << "CCW " << area << endl;
        } else {
            cout << "CW " << area << endl;
        }
        cin >> n;
    }
}