#include <iostream>
#include <string>

int main() {
    int l, x;
    std::cin >> l >> x;
    std::string event;
    int count = 0;
    int tmp = 0;
    int ret = 0;
    for (int i = 0; i < x; i++) {
        std::cin >> event >> tmp;
        if (event == "enter") {
            if (count + tmp > l) {
                ret++;
            } else {
                count += tmp;
            }
        }
        if (event == "leave") {
            count -= tmp;
        }
    }
    std::cout << ret << std::endl;
}