#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::getline(std::cin, s);
    std::cout << "Thank you, " << s << ", and farewell!";
}
