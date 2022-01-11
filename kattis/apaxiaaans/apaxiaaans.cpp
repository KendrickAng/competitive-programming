#include <iostream>
#include <string>

int main() {
    int p1 = 0;
    int p2 = 0;
    std::string in;
    std::string out = "";
    std::cin >> in;
    while (p2 < in.size()) {
        if (p1 == p2)  {
            out.push_back(in[p1]);
        }
        p2++;
        if (in[p1] != in[p2])  {
            p1 = p2;
        }
    }
    std::cout << out << std::endl;
}