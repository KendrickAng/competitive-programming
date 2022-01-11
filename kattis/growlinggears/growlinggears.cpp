#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int maxIdx = -1;
        int maxTorque = -1;
        for (int i = 1; i <= n; i++) {
            int a, b, c; cin >> a >> b >> c;
            double R = (double) b / (2*a);
            double deriv = -(a * R * R) + (b * R) + c;
            if (deriv > maxTorque) {
                maxIdx = i;
                maxTorque = deriv;
            }
        }
        cout << maxIdx << endl;
    }
}
