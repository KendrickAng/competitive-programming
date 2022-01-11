#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::string s = std::bitset<32>(n).to_string();
    std::string rs = "";
    bool copying = false;
    for (int i = 0; i < s.size(); i++) {
        if (copying) {
            rs.push_back(s[i]);
        } else if (s[i] == '1') {
            copying = true;
            rs.push_back(s[i]);
        }
    }
    std::reverse(rs.begin(), rs.end());
    std::cout << std::bitset<32>(rs).to_ulong() << std::endl;
}