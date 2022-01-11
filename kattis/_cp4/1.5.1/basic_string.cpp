#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string join(vector<string> v, string delim) {
    string ret = "";
    bool first = true;
    for (auto a: v) {
        if (first) {
            first = false;
        } else {
            ret += delim;
        }
        ret += a;
    }
    return ret;
}

int main() {
    string s;
    vector<string> arr{};
    while(getline(cin, s)) {
        if (strncmp(s.c_str(), ".......", 7) == 0) {
            break;
        }
        arr.push_back(s);
    }
    cout << join(arr, " ");
}