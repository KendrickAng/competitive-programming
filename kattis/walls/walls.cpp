#include <iostream>
#include <vector>
#include <cmath>

int MAX = 100;

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    double xx = abs(x1-x2);
    double yy = abs(y1-y2);
    return sqrt(xx*xx + yy*yy);
}

int bitcount(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n & (n-1);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    double l, w, r; cin >> l >> w >> n >> r;
    vector<pair<double, double>> walls = {
        {-l/2, 0}, {l/2, 0}, {0, -w/2}, {0, w/2}
    };

    vector<pair<double, double>> cranes;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cranes.push_back({x, y});
    }

    // check if solvable
    for (auto [x1, y1]: walls) {
        bool inReach = false;
        for (auto [x2, y2]: cranes) {
            if (distance(x1,y1,x2,y2) <= r) {
                inReach = true; break;
            }
        }
        if (!inReach) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        auto [x1, y1] = cranes[i];
        bool canReach[] = {false, false, false, false};
        for (int i = 0; i < 4; i++) {
            auto [x2, y2] = walls[i];
            if (distance(x1,y1,x2,y2) <= r) {
                canReach[i] = true;
            }
        }
        if (canReach[0] && canReach[1] && canReach[2] && canReach[3]) {
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1+1; i2 < n; i2++) {
            vector<int> selectedCranes = {i1,i2};
            bool canReach[] = {false, false, false, false};
            for (int sc: selectedCranes) {
                auto [x1, y1] = cranes[sc];
                for (int i = 0; i < 4; i++) {
                    auto [x2, y2] = walls[i];
                    if (distance(x1,y1,x2,y2) <= r) {
                        canReach[i] = true;
                    }
                }
            }
            if (canReach[0] && canReach[1] && canReach[2] && canReach[3]) {
                cout << 2 << endl;
                return 0;
            }
        }
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1+1; i2 < n; i2++) {
            for (int i3 = i2+1; i3 < n; i3++) {
                vector<int> selectedCranes = {i1,i2,i3};
                bool canReach[] = {false, false, false, false};
                for (int sc: selectedCranes) {
                    auto [x1, y1] = cranes[sc];
                    for (int i = 0; i < 4; i++) {
                        auto [x2, y2] = walls[i];
                        if (distance(x1,y1,x2,y2) <= r) {
                            canReach[i] = true;
                        }
                    }
                }
                if (canReach[0] && canReach[1] && canReach[2] && canReach[3]) {
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }

    // definitely solvable; now try all subsets
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1+1; i2 < n; i2++) {
            for (int i3 = i2+1; i3 < n; i3++) {
                for (int i4 = i3+1; i4 < n; i4++) {
                    vector<int> selectedCranes = {i1,i2,i3,i4};
                    int cranesUsed = 0;
                    bool canReach[] = {false, false, false, false};
                    for (int sc: selectedCranes) {
                        auto [x1, y1] = cranes[sc];
                        for (int i = 0; i < 4; i++) {
                            auto [x2, y2] = walls[i];
                            if (distance(x1,y1,x2,y2) <= r) {
                                canReach[i] = true;
                            }
                        }
                    }
                    if (canReach[0] && canReach[1] && canReach[2] && canReach[3]) {
                        cout << 4 << endl;
                        return 0;
                    }
                }
            }
        }
    }
}