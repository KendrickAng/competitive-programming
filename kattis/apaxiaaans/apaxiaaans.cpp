#include <iostream>
#include <string>

int main() {
    char p1;
    std::string in;
    std::string out = "";
    std::cin >> in;
    for (char c: in) {
        if (c != p1) {
            p1 = c;
            out.push_back(c);
        }
    }
    std::cout << out << std::endl;
}