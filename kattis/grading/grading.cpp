#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    int score; cin >> score;
    if (score >= a) {
        cout << "A" << endl;
    } else if (score >= b) {
        cout << "B" << endl;
    } else if (score >= c) {
        cout << "C" << endl;
    } else if (score >= d) {
        cout << "D" << endl;
    } else if (score >= e) {
        cout << "E" << endl;
    } else {
        cout << "F" << endl;
    }
}