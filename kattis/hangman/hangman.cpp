#include <iostream>
#include <set>
#include <string>

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    std::set<char> c{};
    for (char cc: a) c.insert(cc);
    int wrong = 0;
    bool win = false;
    for (char ccc: b) {
        if (c.count(ccc)) {
            c.erase(ccc);
        } else {
            wrong ++;
        }
        if (c.empty()) {
            win = true; break;
        }
        if (wrong >= 10) {
            win = false; break;
        }
    }
    if (win) std::cout << "WIN" << std::endl;
    else std::cout <<"LOSE" <<std::endl;
}