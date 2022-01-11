#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int b, k, g; cin >> b >> k >> g;
    int groups = k / g;
    int days = 0;

    while (b > 1) {
        b -= groups;
        days++;
    }

    cout << days << endl;
}
