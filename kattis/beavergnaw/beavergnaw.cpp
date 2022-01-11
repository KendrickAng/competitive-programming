#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

int main() {
    double D, v; cin >> D >> v;
    while (D != 0 && v != 0) {
        double a = PI * (D/2) * (D/2) * D;
        double b = a - v;
        double c = cbrt(((6.0*b/PI) - (D*D*D)) / 2);
        cout << fixed << setprecision(10) << c << endl;
        cin >> D >> v;
    }
}