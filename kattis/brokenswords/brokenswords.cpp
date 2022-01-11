#include <iostream>

int main() {
    char T, B, L, R, N;
    int TB, LR;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> T >> B >> L >> R;
        if (T == '0') TB++;
        if (B == '0') TB++;
        if (L == '0') LR++;
        if (R == '0') LR++;
    }
    int swords = 0;
    while (TB >= 2 && LR >= 2) {
        TB -= 2;
        LR -= 2;
        swords++;
    }
    std::cout << swords << ' ' << TB << ' ' << LR << std::endl;
}