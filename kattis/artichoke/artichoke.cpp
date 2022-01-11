#include <iostream>
#include <cmath>
#include <iomanip>

double price(int k, int p, int a, int b, int c, int d) {
    return p * (std::sin(a*k + b) + std::cos(c*k + d) + 2);
}

int main() {
    int p, a, b, c, d, n;
    std::cin >> p >> a >> b >> c >> d >> n;
    double mx = -1;
    double dec = 0;
    double mn = -1;
    for (int i = 1; i <= n; i++) {
        double pri = price(i, p, a, b, c, d);
        if (mx == -1 && mn == -1) {
            mx = pri;
            mn = pri;
        }
        else if (pri > mx) {
            mx = pri;
            mn = pri;
        }
        else if (pri <= mn) {
            mn = pri;
            dec = std::max(dec, mx - mn);
        }
        else {
            // do nothing, price in middle of max and min
        }
    }
    std::cout << std::setprecision(10) << dec << std::endl;
}
