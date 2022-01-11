#include <iostream>
#include <numeric>

int main() {
    int num, denom;
    char dump;
    std::cin >> num >> dump >> denom;
    num -= 32 * denom;
    num *= 5;
    denom *= 9;
    int gcd = std::gcd(num, denom);
    std::cout << num/gcd << '/' << denom/gcd << std::endl;
}