#include <iostream>
#include <string>

std::string garbage;

int main() {
    int N;
    std::cin >> N;
    std::getline(std::cin, garbage);
    for (int i = 0; i < N; i++) {
        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd.substr(0, 10) == "Simon says") {
            std::cout << cmd.substr(10) << std::endl;
        }
    }
}