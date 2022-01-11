#include <iostream>
#include <string>

int main() {
    std::string seq;
    std::cin >> seq;
    int pos = 1;
    // A: 2 - 1, B: 3 - 2, C: 3 - 1
    for (int i = 0; i < seq.size(); i++) {
        char c = seq[i];
        if (c == 'A') {
            if (pos == 1) pos = 2;
            else if (pos == 2) pos = 1;
        }
        if (c == 'B') {
            if (pos == 2) pos = 3;
            else if (pos == 3) pos = 2;
        }
        if (c == 'C') {
            if (pos == 1) pos = 3;
            else if (pos == 3) pos = 1;
        }
    }
    std::cout << pos << std::endl;
}
