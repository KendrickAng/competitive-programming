#include <iostream>
#include <string>
#include <queue>

void reset(bool &r, bool &b, bool &l, std::queue<char> &q) {
    r = false;
    b = false;
    l = false;
    q = {};
}

void poptill(char c, std::queue<char> &mem, std::string &ret, bool &R, bool &B, bool &L) {
    char tmp{};
    while (tmp != c) {
        tmp = mem.front();
        mem.pop();
        if (tmp == 'R') {
            R = false;
            ret += 'S';
        } else if (tmp == 'B') {
            B = false;
            ret += 'K';
        } else if (tmp == 'L') {
            L = false;
            ret += 'H';
        }
    }
}

int main() {
    bool R = false;
    bool B = false;
    bool L = false;
    std::queue<char> mem{};
    char next;
    std::string ret = "";
    // invariant: at most one of each char in the queue at any time
    while (std::cin >> next) {
        if (next == 'R') {
            if (B && L) {
                reset(R,B,L,mem);
                ret += 'C';
                continue;
            } else if (R) {
                // pop and add to return string until we get R
                poptill('R', mem, ret, R, B, L);
            }
            R = true;
            mem.push('R');
        } else if (next == 'B') {
            if (R && L) {
                reset(R,B,L,mem);
                ret += 'C';
                continue;
            } else if (B) {
                poptill('B', mem, ret, R, B, L);
            }
            B = true;
            mem.push('B');
        } else if (next == 'L') {
            if (R && B) {
                reset(R,B,L,mem);
                ret += 'C';
                continue;
            } else if (L) {
                poptill('L', mem, ret, R, B, L);
            }
            L = true;
            mem.push('L');
        }
    }
    while (!mem.empty()) {
        char tmp = mem.front();
        mem.pop();
        if (tmp == 'R') {
            R = false;
            ret += 'S';
        } else if (tmp == 'B') {
            B = false;
            ret += 'K';
        } else if (tmp == 'L') {
            L = false;
            ret += 'H';
        }
    }
    std::cout << ret << std::endl;
}
