#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string N, M;
    std::string retN = "";
    std::string retM = "";
    std::cin >> N >> M;
    // pad 
    if (N.length() > M.length()) {
        M = std::string(N.length() - M.length(), '0').append(M);
    }
    if (M.length() > N.length()) {
        N = std::string(M.length() - N.length(), '0').append(N);
    }
    for (int i = 0; i < N.length(); i++) {
        int n = N[i] - '0';
        int m = M[i] - '0';
        if (n < m) {
            retM += (m + '0');
        }
        if (n > m) {
            retN += (n + '0');
        }
        if (n == m) {
            retM += (m + '0');
            retN += (n + '0');
        }
    }
    if (retN == "") {
        std::cout << "YODA\n";
    } else {
        std::cout << std::stoi(retN) << std::endl;
    }
    if (retM == "") {
        std::cout << "YODA\n";
    } else {
        std::cout << std::stoi(retM) << std::endl;
    }
}