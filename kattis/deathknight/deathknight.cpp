#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line;
    int ret = 0;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (line.find("CD") == string::npos) {
            ret++;
        }
    }
    cout << ret << endl;
}