#include <iostream>

int main() {
    int k; std::cin >> k;
    int a = 1;
    int b = 0;
    for (int i = 0; i < k; i++) {
        int olda = a;
        int oldb = b;
        a += oldb;
        a -= olda;
        b += olda;
    }
    std::cout << a << " " << b << std::endl;
}