#include <iostream>

using namespace std;

string multiplier(int i) {
    if (i == 1) return "single";
    if (i == 2) return "double";
    if (i == 3) return "triple";
}

int main() {
    int n; cin >> n;

    for (int d1 = 1; d1 <= 20; d1++) {
        for (int d1m = 1; d1m <= 3; d1m++) {
            int a = d1 * d1m;
            if (a == n) {
                cout << multiplier(d1m) << " " << d1 << endl;
                return 0;
            }
            for (int d2 = 1; d2 <= 20; d2++) {
                for (int d2m = 1; d2m <= 3; d2m++) {
                    int b = d2 * d2m;
                    if (a + b == n) {
                        cout << multiplier(d1m) << " " << d1 << endl;
                        cout << multiplier(d2m) << " " << d2 << endl;
                        return 0;
                    }
                    for (int d3 = 1; d3 <= 20; d3++) {
                        for (int d3m = 1; d3m <= 3; d3m++) {
                            int c = d3 * d3m;
                            if (a + b + c == n) {
                                cout << multiplier(d1m) << " " << d1 << endl;
                                cout << multiplier(d2m) << " " << d2 << endl;
                                cout << multiplier(d3m) << " " << d3 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "impossible" << endl;
}
