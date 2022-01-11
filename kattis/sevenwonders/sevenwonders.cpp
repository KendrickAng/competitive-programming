#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    char c;
    int T = 0;
    int C = 0;
    int G = 0;
    while (std::cin >> c) {
        if (c == 'T') T++;
        if (c == 'C') C++;
        if (c == 'G') G++;
    }
    int sets = std::min({T,C,G});
    int points = std::pow(T, 2) + std::pow(C, 2) + std::pow(G, 2) + sets * 7;
}