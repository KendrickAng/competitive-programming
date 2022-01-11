#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

int main () {
    std::string s;
    std::cin >> s;
    int whitespace = 0;
    int lower = 0;
    int upper = 0;
    int symbols = 0;
    int total = 0;
    for (char c: s) {
        if (c == '_') whitespace++;
        else if (islower(c)) lower++;
        else if (isupper(c)) upper++;
        else symbols++;
        total++;
    }
    std::cout << std::setprecision(15) << (double) whitespace/total << std::endl;
    std::cout <<std::setprecision(15) << (double) lower/total << std::endl;
    std::cout << std::setprecision(15) <<(double) upper/total << std::endl;
    std::cout <<std::setprecision(15) << (double) symbols/total << std::endl;

}