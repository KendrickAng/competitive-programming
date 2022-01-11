#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string s1, s2;
    s1 = s.substr(0, s.length()/2);
    s2 = s.substr(s.length()/2);
    int rs1 = 0;
    int rs2 = 0;
    for (char c: s1) rs1 += (c-'A');
    for (char c: s2) rs2 += (c-'A');
    for (char &c: s1) {
        c = ((((int) c - 'A') + rs1) % 26) + 'A';
    }
    for (char &c: s2) {
        c = ((((int) c - 'A') + rs2) % 26) + 'A';
    }
    for (int i = 0; i < s1.length(); i++) {
        char c = (((s1[i]-'A') + (s2[i]-'A')) % 26) + 'A';
        std::cout << c;
    }
    std::cout << std::endl;
}