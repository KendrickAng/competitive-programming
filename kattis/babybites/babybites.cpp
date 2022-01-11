#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string ans = "makes sense";
    for (int i = 1; i <= n; i++) {
        std::string s; std::cin >> s;
        if (s == "mumble") {
            continue;
        } else if (std::stoi(s) != i) {
            ans = "something is fishy";
            break;
        }
    }
    std::cout << ans << std::endl;
}