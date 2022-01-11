#include <iostream>
#include <regex>

int main() {
    std::string s;
    std::getline(std::cin, s);
    s = std::regex_replace(s, std::regex("apa"), "a");
    s = std::regex_replace(s, std::regex("epe"), "e");
    s = std::regex_replace(s, std::regex("ipi"), "i");
    s = std::regex_replace(s, std::regex("opo"), "o");
    s = std::regex_replace(s, std::regex("upu"), "u");
    std::cout << s << std::endl;
}