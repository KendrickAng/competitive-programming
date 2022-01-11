#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> words;
    string ans;
    int a, b; cin >> a >> b;

    // generate words
    for (char c1 = 'a'; c1 < 'z'; c1++) {
        for (char c2 = 'a'; c2 < 'z'; c2++) {
            for (char c3 = 'a'; c3 < 'z'; c3++) {
                for (char c4 = 'a'; c4 < 'z'; c4++) {
                    string tmp = "";
                    tmp.push_back(c1);
                    tmp.push_back(c2);
                    tmp.push_back(c3);
                    tmp.push_back(c4);
                    words.push_back(tmp);
                }
            }
        }
    }

    for (int i = 0; i < b; i++) {
        if (i != 0) {
            ans.append(" ");
        }
        ans.append(words[i]);
    }
    cout << ans << endl;
}