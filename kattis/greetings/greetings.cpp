#include <iostream>
#include <string>

int main() {
    std::string sIn, sOut;
    std::cin >> sIn;
    int numE = (sIn.size() - 2) * 2;
    sOut = "h";
    for (int i = 0; i < numE; i++) {
        sOut.push_back('e');
    }
    sOut.push_back('y');
    std::cout << sOut << std::endl;
}