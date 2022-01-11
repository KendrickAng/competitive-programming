#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a; cin >> a;
        int k = a%11;
        if ((a - k*111) < 0)
            cout << "NO" << endl;
        else if ((a - k*111) % 11 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
