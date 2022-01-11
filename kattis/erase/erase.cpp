#include <iostream>
#include <bitset>

int main() {
    int n;
    std::cin >> n;
    std::string before, after;
    std::cin >> before >> after;
    bool success = false;
    if (n % 2 == 0) {
        if (before == after) success = true;
    } else {
        success = true;
        for (int i = 0; i < before.length(); i++) {
            if (before[i] == after[i]) success = false;
        }
    }
    if (success) {
        std::cout << "Deletion succeeded" << std::endl;
    } else {
        std::cout << "Deletion failed" << std::endl;
    }
}