#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s; std::cin >> s;
    int bs = 0;
    std::string ret = "";
    for (int i = s.size()-1; i >= 0; i--) {
        char c = s[i];
        if (c == '<') {
            bs++;
            continue;
        }
        else if (bs > 0) {
            bs--;
            continue;
        }
        else {
            ret.push_back(c);
        }
    }
    std::reverse(ret.begin(), ret.end());
    std::cout << ret << std::endl;
}