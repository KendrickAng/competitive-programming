#include <iostream>
#include <string>

int main() {
    std::string jon, doctor;
    std::cin >> jon >> doctor;
    if (jon.length() >= doctor.length()) {
        std::cout << "go" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}
