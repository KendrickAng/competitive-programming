#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<char, std::string> alpha_map{
            {'A', "@"},
            {'B', "8"},
            {'C', "("},
            {'D', "|)"},
            {'E', "3"},
            {'F', "#"},
            {'G', "6"},
            {'H', "[-]"},
            {'I', "|"},
            {'J', "_|"},
            {'K', "|<"},
            {'L', "1"},
            {'M', "[]\\/[]"},
            {'N', "[]\\[]"},
            {'O', "0"},
            {'P', "|D"},
            {'Q', "(,)"},
            {'R', "|Z"},
            {'S', "$"},
            {'T', "']['"},
            {'U', "|_|"},
            {'V', "\\/"},
            {'W', "\\/\\/"},
            {'X', "}{"},
            {'Y', "`/"},
            {'Z', "2"}
    };
    std::string s;
    std::getline(std::cin , s);
    for (char c: s) {
        char c2 = std::toupper(c);
        if (alpha_map.find(c2) != alpha_map.end()) {
            std::cout << alpha_map[c2];
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}